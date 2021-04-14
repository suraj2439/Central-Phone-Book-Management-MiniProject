#include "backend.h"

using namespace std;

void node::init_node() {
	this->parent = NULL;
	int i;
	for(i=0;i<10;i++)
		this->child[i] = NULL;
}

void leaf_node::init_leaf_node() {
	int i;
	this->parent = NULL;	
}

vector<char> number_all[1000];
vector<string> number;
int number_count = 0;

Trie::Trie() {
	root = new node;
	root->parent = NULL;
	for(int i = 0;i<10;i++)
		root->child[i] = NULL;
	this->history = new History;
}


void Trie::insert_number(std::string number) {
	int k = number.size(), i = number[0] - '0', j = 0;
	int size = (int)number.size();
	node *p = root->child[i], *q = root, *n;
	leaf_node *l;
	while(p) {                        // omitting entered part
		j++;
		i = number[j] - '0';
		if(j == size - 2)
			p = (leaf_node*)p;
		if(j == size - 1)
			q = (leaf_node*)q;
		q = p;
		p = p->child[i];
	}
	if(k == 0)
		return;
	if(q == NULL)
		return;
	for(; j < size; j++) {
		//printf("%c ",number[j]);
		if(j != size-1) {
			n = new node;
			n->init_node();
			i = number[j] - '0';
			q->child[i] = n;
			n->ch = i;
			n->parent = q;
			q = q->child[i];
		}
		else if(j == size-1) {
			n = new leaf_node;
			n->init_node();
			i = number[j] - '0';
			q->child[i] = (leaf_node*)q->child[i];
			q->child[i] = n;
			n->ch = i;
			n->parent = q;					
		}
	}

	history->store_history(number, INSERT_NO);
}


int Trie::is_present(std::string num) {
	node *p = root;
	int k;
	int size = (int)num.size();
	for(int i = 0; i < size; i++) {
		k = num[i] - '0';
		if(p->child[k] == NULL) {
			////printf("NO");
			return 0;
		}
		if(i == size-1)
			p->child[i] = (leaf_node*)p->child[i];
		p = p->child[k];	
	}
	//printf("YES");
	return 1;	
}

void Trie::insert_info(std::string num,info* information) {
	node *p = root;
	leaf_node *q;
	int k;
	int size = (int)num.size();
	for(int i = 0; i < size; i++) {
		k = num[i] - '0';
		if(p->child[k] == NULL) {
			return ;
		}
		if(i == size-1){
			p->child[i] = (leaf_node*)p->child[i];
		}
		p = p->child[k];
	}	
	//printf(" %d ",p->ch);
	p->inf = new info;
	p->inf = information;	
}


std::string Trie::get_info_one(std::string num, int mode) {
	node *p = root;
	int k;
	int size = (int)num.size();
	std::string st;
	for(int i = 0; i < size; i++) {
		k = num[i] - '0';
		if(p->child[k] == NULL) {
			return st;
		}
		if(i == size)
			p->child[i] = (leaf_node*)p->child[i];
		p = p->child[k];
		//printf(" %d ",p->ch);
	}		
	if(mode == 1){
		//printf(" %s ",p->inf->name);
		return p->inf->name;
	}
	else if(mode == 2){
		//printf(" %s ",p->inf->email);
		return p->inf->email;
	}
	else if(mode == 3){
		//printf(" %s ",p->inf->company);
		return p->inf->company;
	}
	return "Invalid Mode";
}


info* Trie::get_info(std::string num) {
	node *p = root;
	info *inf = new info;
	int k;
	int size = (int)num.size();
	for(int i = 0; i < size; i++) {
		k = num[i] - '0';
		if(p->child[k] == NULL) {
			return inf;
		}
		if(i == size)
			p->child[i] = (leaf_node*)p->child[i];
		p = p->child[k];
		//printf(" %d ",p->ch);
	}	
	return p->inf;
}


void Trie::delete_number(std::string number) {
	node *nn = root;

	if(number.size() == 0)
		return;
	char ch;
	int arr[MAX_SUBSTRING];
	for(int i = 0; i < number.length(); i++){
        	ch = number[i];
	        int x = ch - 48;
        	arr[i] = x;
	}	
	
	if(nn == NULL)
		return;

	node* tempptr = nn;
	int count=0;
	while(count < number.length()){
		int temp = arr[count];
		//cout<< temp <<endl;
		if(tempptr->child[temp] == NULL){
			return;
		}
		tempptr = tempptr->child[temp];
		count += 1;
	}
	//cout << "found"<<endl;

	tempptr = tempptr->parent;
	int size = number.length();
	int temp = arr[size-1];
	tempptr->child[temp] = NULL;
	while(1){
		int cheak_all_null;
		for(int i = 0; i < 10; i++){
			if(tempptr->child[i] == NULL){
				cheak_all_null += 1;
			}
		}
		if(cheak_all_null == 10){
			tempptr = tempptr->parent;
			int count = 0;
			int temp = arr[size-1-count];
			tempptr->child[temp] = NULL;
			count +=1;
		}
		else{
			return;
		}
	}
}


void Trie::traverse_directory(){
	go_to_end(root);
			
}


History Trie::get_history() {
	return *history;
}

int History::get_historyPageNo() {
	return historyPageNo;
}

void History::set_historyPageNo(int no) {
	historyPageNo = no;
	return;	
}

/*
void display_number_via_substring(node* nn, std::string number){
	
	//if present node is null
	if(nn == NULL)
		return;
	
	//if character not found then traverse forward
	if(number[0] - '0' != nn->ch){
		int i;
		for(i=0;i<10;i++){
			display_number_via_substring(nn->child[i],number);
		}
		return;
	}
	
	//if first character matches
//	//printf(" %d ",nn->c);
	int flag = 0, i, num;
	int len = number.size();
	for(i = 1;i < len; i++){
		num = number[i] - '0';
//		//printf(" |%d| |%d| ",num,i);
		if(nn->child[num] == NULL){
			flag = 1;
			break;
		}
		nn = nn->child[num];
	}
	if(flag == 0){
		//printf("FOUND ");
		display_prev(nn);
		display_fwd(nn);
	}
	
	if(flag == 1){
		int i;
		for(i=0;i<10;i++){
			display_number_via_substring(nn->child[i],number);
		}
		return;
	}
}

void display_prev(node *nn){
	if(nn == NULL)
		return;
	display_prev(nn->parent);
	//if(strlen(&nn->ch) <= 1)
		//printf(" %d ", (int)nn->ch );

}


void display_fwd(node *nn){
	int i,flag = 0;
	for(i=0;i<10;i++){
		if(nn->child[i] != NULL){
			flag = 1;
			//printf(" %d ",nn->child[i]->ch);
			display_fwd(nn->child[i]);
		}
	}
	//if(flag == 0)
		//printf(",");
}*/


/*
std::vector<string> take_number_via_substring(node* nn, char *number){
	std::vector<string> numbers;
	//if present node is null
	if(nn == NULL)
		return;

	//if character not found then traverse forward
	if(number[0] - '0' != nn->ch) {
		int i;
		for(i=0;i<10;i++){
			take_number_via_substring(nn->child[i],number);
		}
		return numbers;
	}

	//if first character matches

	int flag = 0, i, num;
	int len = strlen(number);
	for(i = 1;i < len; i++){
		num = number[i] - '0';

		if(nn->child[num] == NULL){
			flag = 1;
			break;
		}
		nn = nn->child[num];
	}
	if(flag == 0){
		printf("FOUND ");
		string temp1 = take_prev(nn);
		string temp2 = take_fwd(nn);

		string result = temp1 + temp2;

		numbers.push_back(result);
	}

	if(flag == 1){
		int i;
		for(i=0;i<10;i++){
			take_number_via_substring(nn->child[i],number);
		}
		return numbers;
	}
}

string take_prev(node *nn){
	if(nn == NULL)
		return;
	string arr[MAX];
	int i = 0;
	take_prev(nn->parent);
	if(strlen(&nn->ch) <= 1)
		arr[i] =  (int)nn->ch;
		i+=1;

	return arr;
}


string take_fwd(node *nn){
	int i,flag = 0;
	string arr[MAX];

	for(i=0;i<10;i++){
		if(nn->child[i] != NULL){
			flag = 1;
			arr[i] = nn->child[i]->ch;
			take_fwd(nn->child[i]);
		}
	}
	if(flag == 0)
		return arr;

	return arr;
}
*/



// Codes for specific events

//cheaks given number is valid or not
bool isNumber(string s)
{
    if(s.length()<10 || s.length()<13)
        return false;
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

//cheaks given name is valid or not
bool isName(string s)
{
    for (int i = 0; i < s.length(); i++)
	    if (isalpha(s[i]) == false && isspace(s[i]) == false)
		    return false;

	return true;
}

//cheaks aadhar number is valid or not
bool isAadhar(string s)
{
    if(s.length() !=12)
        return false;
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}




void go_to_end(node *nn){
	if(nn == NULL)
		return;
	node *p = nn;
	int i, flag = 0;
	for(i=0;i< 10;i++){
		go_to_end(nn->child[i]);
		if(nn->child[i] == NULL)
			flag++;
	}
	if(flag == 10){
		vector<char> v1;
		v1.push_back(nn->ch);
		fill_vector(nn->parent,v1);
//		//printf("%d ",nn->ch );
	}
}

void fill_vector(node *nn,vector<char> v){
	if(nn->parent == NULL){
		number_all[number_count++] = v;
		return;
	}
	vector<char> v1 = v;
	v1.push_back(nn->ch);
	fill_vector(nn->parent,v1);
}


void store_vector_into_string(){
	int k = number_count, i, j;
	std::string str;
	for(i = 0;i < number_count; i++){
		str = "\0";
		for(j = number_all[i].size();j>=0;j--){
			str = str + number_all[i][j];
		}
		number.push_back(str);
	}
	//printf(" %ld ",number.size());
}




// class containing functions to store and retrive 
// history of operations perforemd
History :: History() { 
	time(&base_time);
	historyPageNo = 0;
}
	

int History :: binary_search(std :: vector<hstry> his, time_t time) {
	int mid;
	int low = 0;
	int high = his.size();
			
	while (low < high) {
		mid = low + (high - low) / 2;
				
		if (time <= his[mid].time)
			high = mid;
		else 
			low = mid + 1;
	}
	return low;
}



// func to return current time
// time will be stored as number of seconds elapsed from init of constructor of History		
time_t History :: get_time() {
	return time(NULL) - base_time;
}


// func to store history history of operation
void History :: store_history(std :: string num, int operation) {
	hstry h;
	h.time = time(NULL) - base_time;	
	h.num = num;
	h.operation = operation;
	h.info_H = NULL;

	history.push_back(h);
	return;
}


// func overloading , use to store history of operation		
void History :: store_history(std :: string num, int operation, info Inf) {
	hstry h;
	h.time = time(NULL) - base_time;
	h.num = num;
	h.operation = operation;
	h.info_H = new info;
	*(h.info_H) = Inf;

	history.push_back(h);
	return;
}


// function to retrive all history 
std :: vector<hstry> History :: retrive() {
	std :: vector<hstry> res = history;
	return res;
}


// func to retrive N units of history from given time
std :: vector<hstry> History :: retrive(time_t time, int N) {
	std :: vector<hstry> res;
	// apply lower bound for time
	int indx = binary_search(history, time);
	for(int i = 0; i < N && i < history.size(); i++)
		res.push_back(history[i]);

	return res;
}


// func to retrive history between two time time1 and time2, time1 < time2
std :: vector<hstry> History :: retrive(time_t time1, time_t time2) {
	std :: vector<hstry> res;
	// applyl lower bound for time1
	int indx = binary_search(history, time1);

	for(int i = 0; i < history.size() && history[i].time <= time2; i++)
		res.push_back(history[i]);

	return res;
}


void History :: print() {
	for(int i = 0; i < history.size(); i++)
		std :: cout<<history[i].num<< std :: endl;
	return;
}






// class to wrap the functions which use to generate numbers based upon 
// type(mobile no, landline no) of number
// country code(for mobile no) and area code(for landline no)
// vip number(user can give last N digits, N <= 4)
Generator :: Generator(){ 
	
}

char Generator :: getrandomdigit() {
	return (rand() % 10) + 48;
}

// function overloading
char Generator :: getrandomdigit(int flag) {
	return (6 + rand() % 4) + 48;
}
	


// func to generate number based on type(mobile no/ landline no) 
// and counry code/area code
std :: string Generator :: generate_number(int type, int country_or_area_code) {
	std :: string result;
	result = result + std :: to_string(country_or_area_code);
	int rem = 9;
	if(type == LANDLINE_NO)
		rem = 7;
	else result.push_back(getrandomdigit(FIRST_DIGIT));
	for(int i = 0; i < rem; i++)
		result.push_back(getrandomdigit());
	return result;
}
	
		
// func overloading, func use to generate vip number 	
std :: string Generator :: generate_number(int type, int country_or_area_code, int size, int vip) {
	std :: string res;
	res = res + std :: to_string(country_or_area_code);
	int rem = 9 - size;

	if(type == LANDLINE_NO)
		rem = 7 - size;
	else res.push_back(getrandomdigit(FIRST_DIGIT));
	for(int i = 0; i < rem; i++)
		res.push_back(getrandomdigit());
	res = res + std :: to_string(vip);
	return res;
}
	

//cheaks given number is valid or not
bool Validator::isPhoneNumber(std::string s) {
	if(s.length()<10 || s.length() == 0 || s.length()>13)
        	return false;
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;
	return true;
}


//cheaks given name is valid or not
bool Validator::isName(std::string s) {
	if(s.length() == 0)
		return false;
	for (int i = 0; i < s.length(); i++)
	    if (isalpha(s[i]) == false && isspace(s[i]) == false)
		    return false;

	return true;
}

//cheaks aadhar number is valid or not
bool Validator::isAadhar(std::string s) {
	if(s.length() !=12)
        	return false;
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

bool Validator::isNumber(std::string s) {
	if(s.length() == 0)
		return false;
	for (int i = 0; i < s.length(); i++)
                if (isdigit(s[i]) == false)
                        return false;
	return true;
}

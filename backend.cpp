#include "backend.h"

using namespace std;

void node::init_node() {
	this->parent = NULL;
	int i;
	for(i=0;i<10;i++)
		this->child[i] = NULL;
}

void leaf_node::init_leaf_node() {
	//int i;
	this->parent = NULL;	
}


Trie::Trie() {
	root = new node;
	root->parent = NULL;
	for(int i = 0;i<10;i++)
		root->child[i] = NULL;
	this->history = new History;
    homeTablePageNo = 0;
}

void Trie::Load_Directory(){
  ifstream ip("directory.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string number;
  string name;
  string email;
  string company;
	string aadharNo;
	string address;
	string country_code;
	string country;

	info* new_info = new info;

  while(ip.good()){

		getline(ip,country_code,',');
    getline(ip,number,',');
    getline(ip,name,',');
    getline(ip,email,',');
		getline(ip,company,',');
		getline(ip,aadharNo,',');
		getline(ip,address,',');
    getline(ip,country,'\n');
  
		set_code_info(country_code, country);
		char code = get_code_key(country_code);
//		cout<<code<<endl;
//		cout<<code<<" "<<country_code;
		short int int_country_code = code;
//		cout<<" "<<int_country_code<< endl ;
		//storing all information in new_info
		new_info->country_code = int_country_code;
		new_info->company = company;
		new_info->aadharNo = aadharNo;
		new_info->email = email;
		new_info->name = name;
		new_info->address = address;
		//inserting number and info one by one
		insert_number(number,new_info);

	number.clear();
  name.clear();
  email.clear();
  company.clear();
	aadharNo.clear();
	address.clear();
	country_code.clear();
	country.clear();
	}
  ip.close();
}

void Trie::Load_Data_in_file( ){
	char countrycode;
	string number;
  string name;
  string email;
  string company;
	string aadharNo;
	string address;
	string country_code;
	string country;
	info* new_info = new info;
	int intcountrycode;

	ofstream ip;
	ip.open("directory.csv",ofstream::out | ofstream::trunc);
	ip.close();

	ip.open("directory.csv");

	vector<string> s = traverse_directory();

	for(int i = 0; i < s.size();i++ ){
		if(i > 0){
			ip<<endl;
		}
		countrycode = s[i][0] ;
		country_code = get_code_key(countrycode);
		country = get_code_info(country_code);
		
		number = s[i].substr(1, 10);
		intcountrycode = s[i][0];
		new_info = get_info(number, intcountrycode);
		name = new_info->name;
		email = new_info->email;
		company = new_info->company;
		aadharNo = new_info->aadharNo;
		address = new_info->address;

		ip<<country_code<<",";
		ip<<number<<",";
		ip<<name<<",";
		ip<<email<<",";
		ip<<company<<",";
		ip<<aadharNo<<",";
		ip<<address<<",";
		ip<<country;

		number.clear();
		name.clear();
		email.clear();
		company.clear();
		aadharNo.clear();
		address.clear();
		country_code.clear();
		country.clear();
		
	}
	ip.close();
}



void Trie::insert_number(std::string number, info *information) {
	int k = number.size(), i = number[0] - '0', j = 0;
	int size = (int)number.size();
	node *p = root->child[i], *q = root, *n;
	//leaf_node *l;
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
  if(p == NULL && q != NULL){
    info tmp = *information;
      q->inf.push_back(tmp);  
  }
	if(k == 0)
		return;
	if(q == NULL)
		return;
	for(; j < size; j++) {
		////printf("%c ",number[j]);
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
      info tmp = *information;
      n->inf.push_back(tmp);

		}
	}
	history->store_history(number, INSERT_NO);
}


int Trie::is_present(std::string num,short int cont_code) {
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
  for(int i=0; i < (int)p->inf.size();i++){
    if(p->inf[i].country_code == cont_code)
      return 1;
  }
	return 0;	
}


int Trie::update_info(std::string num,info* information) {
	history->store_history(num, UPDATE_INFO);

	node *p = root;
	//leaf_node *q;
	int k;
	int size = (int)num.size();
	for(int i = 0; i < size; i++) {
		k = num[i] - '0';
		if(p->child[k] == NULL) {
			return 0;
		}
		if(i == size-1){
			p->child[i] = (leaf_node*)p->child[i];
		}
		p = p->child[k];
	}	
	//printf(" %d ",p->ch);
  int i;
	for(i = 0;i < (int)p->inf.size(); i++){
    if(p->inf[i].country_code == information->country_code)
       p->inf[i] = *information;
    //   cout<<information->country_code;
      return 1;
  }
// cout<<"YES ";
return 0;
//  
}



info* Trie::get_info(std::string num, int cont_code) {
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
  for(int i = 0;i< (int)p->inf.size()-1;i++){
	  if(p->inf[i].country_code == cont_code){
     info *tmp =  &p->inf[i];
     return tmp;
    }
  }
  info *tmp = &p->inf[0];
  return tmp;
}


std::vector<string> Trie::traverse_directory(){
  count = 0;
  vector<char> num;
  vector<vector <char>> number_all;
	go_to_end(root,&number_all);
  for(int i = 0;i < (int)number_all.size();i++){
	  for(int j=0;j<5;j++){
      int k = 10 - j;
      char tmp = number_all[i][j+1];
      number_all[i][j+1] = number_all[i][k];
      number_all[i][k] = tmp;
    }
  }
  vector<string> string_number;
  std::string str, tmpstr = "";
  for(int i=0; i < (int)number_all.size();i++){
    for(int j=0;j<(int)number_all[i].size();j++){
      str = str + number_all[i][j];
    }
    string_number.push_back(str);
    str = tmpstr;
  }
    
	return string_number;	
}

void go_to_end(node *nn,std::vector<std::vector <char>> *v){
	if(nn == NULL)
		return;
	//node *p = nn;
	int i, flag = 0;
	for(i=0;i< 10;i++){
		go_to_end(nn->child[i],v);
		if(nn->child[i] == NULL)
			flag++;
	}
	if(flag == 10 && nn != NULL){
		
    for(int i = 0;i<(int)nn->inf.size();i++){
      vector<char> v1;
      v1.push_back(nn->inf[i].country_code);
		  v1.push_back(nn->ch + '0');
		  fill_vector(nn->parent,v1,v);
    }
	}
}

void fill_vector(node *nn,std::vector<char> v,std::vector<std::vector<char>> *number){
	if(nn->parent == NULL || nn == NULL){
		number->push_back(v);
		return;
	}
	vector<char> v1 = v;
	v1.push_back(nn->ch + '0');
	fill_vector(nn->parent,v1,number);
}

void Trie::delete_number(std::string num,short int cont_code) {
	history->store_history(num, DEL_NO);

     node *p = this->root, *q = NULL;
     //int size = num.size();
     for(int i = 0; i < (int)num.size() ; i++){
        int dat = num[i] - '0';
        q = p;
        p = p->child[dat];
     }
     if(p->inf.size() > 1){
       int len = p->inf.size();
       vector<info> information;
       for(int i = 0;i < len;i++){
         if(p->inf[i].country_code != cont_code)
            information.push_back(p->inf[i]);
       }
       for(int i = 0;i < len || p->inf.size() != 0; i++){
            p->inf.pop_back();
        }
        for(int i = 0;i< len - 1;i++){
          p->inf.push_back(information[i]);
        }
        return;
      }
    q = p->parent;
    int ret = 0;

    int k = p->ch ;
    delete p;
    q->child[k] = NULL;
    for(int i=0;i<10;i++){
      if(q->child[i] != NULL)
        ret++;
      if(ret > 0)
        return;
    }
    p = q;
    q = p->parent;
    while(q != NULL){
	   int k = p->ch;
      for(int i = 0; i < 10; i++){
        if(q->child[i] != p && q->child[i] != NULL)
          return;
      }
      q->child[k] = NULL;
      delete p;
      p = q;
      q = p->parent;
    }
}


void check_substring(node *nn,std::string number, std::vector<std::vector <char>> *v){
	
	//if present node is null
	if(nn == NULL)
		return;
	
	//if character not found then traverse forward
	if(number[0] - '0' != nn->ch){
		int i;
		for(i=0;i<10;i++){
			check_substring(nn->child[i],number,v);
		}
		return;
	}
	
	//if first character matches
	int flag = 0, i, num;
	//node *mm = nn;
	int len = number.size();
	for(i = 1;i < len; i++){
		num = number[i] - '0';
		if(nn->child[num] == NULL ){
			flag = 1;
			break;
		}
		for(int j=0;j<10;j++)
			check_substring(nn->child[j],number,v);
		nn = nn->child[num];
	}

	if(flag == 0){
   		go_to_end(nn,v);
    		return;
	}
	
	if(flag == 1){
		int i;
		for(i=0;i<10;i++){
			check_substring(nn->child[i],number,v);
		}
		return;
	}
  return ;
}


std::vector<std::string> Trie::display_number_via_substring(std::string to_check){
  vector<vector <char>> number_string;
  count = 0;
 // vector<vector <char>> number_string;
  check_substring(root,to_check,&number_string);
   for(int i = 0;i < (int)number_string.size();i++){
	  for(int j=0;j<5;j++){
      int k = 10 - j;
      char tmp = number_string[i][j+1];
      number_string[i][j+1] = number_string[i][k];
      number_string[i][k] = tmp;
    }
  }
  vector<string> string_number;
  std::string str, tmpstr = "";
  for(int i=0;i<(int)number_string.size();i++){
    for(int j=0;j<(int)number_string[i].size();j++){
      str = str + number_string[i][j];
    }
    string_number.push_back(str);
    str = tmpstr;
  } 
  return string_number;
}


int Trie::get_homeTablePageNo() {
    return homeTablePageNo;
}

void Trie::set_homeTablePageNo(int no) {
    homeTablePageNo = no;
    return;
}

int Trie::get_infoTablePageNo() {
    return getInfoTablePageNo;
}

void Trie::set_getInfoTablePageNo(int no) {
    getInfoTablePageNo = no;
    return;
}


char Trie::get_code_key(std::string code) {
	return codes[code].first;
}

std::string Trie::get_code_key(char code) {
	auto it = codes.begin();
	std::pair<char, string> p = it->second;
	while(p.first != code) {
		it++;
		if(it == codes.end())
			return "";
		p = it->second;
	}
	return it->first;
}

std::string Trie::get_code_info(std::string code) {
	return codes[code].second;
}

void Trie::set_code_info(std::string code, std::string code_info) {
	pair<char, std::string> p;
	p.second = code_info;
	codes[code] = p;
	codes[code].first = codes.size();
	return;
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
	for(int i = indx; i-indx < N && i < (int)history.size(); i++)
		res.push_back(history[i]);

	return res;
}


// func to retrive history between two time time1 and time2, time1 < time2
std :: vector<hstry> History :: retrive(time_t time1, time_t time2) {
	std :: vector<hstry> res;
	// applyl lower bound for time1
	int indx = binary_search(history, time1);

	for(int i = indx; i < (int)history.size() && history[i].time <= time2; i++)
		res.push_back(history[i]);

	return res;
}


void History :: print() {
	for(int i = 0; i < (int)history.size(); i++)
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
	if(type == LANDLINE_NO)
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
std :: string Generator :: generate_number(int type, int country_or_area_code, int size, std::string vip) {
	if(size==10)
		return vip;
	std :: string res;
	if(type == LANDLINE_NO)
		res = res + std :: to_string(country_or_area_code);
	int rem = 9 - size;

	if(type == LANDLINE_NO)
		rem = 7 - size;
	else res.push_back(getrandomdigit(FIRST_DIGIT));
	for(int i = 0; i < rem; i++)
		res.push_back(getrandomdigit());
	res = res + vip;
	return res;
}

	

//cheaks given number is valid or not
bool Validator::isPhoneNumber(std::string s) {
	if(s.length()<10 || s.length() == 0 || s.length()>13)
        	return false;
	for (int i = 0; i < (int)s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;
	return true;
}


//cheaks given name is valid or not
bool Validator::isName(std::string s) {
	if(s.length() == 0)
		return false;
	for (int i = 0; i < (int)s.length(); i++)
	    if (isalpha(s[i]) == false && isspace(s[i]) == false)
		    return false;

	return true;
}

//cheaks aadhar number is valid or not
bool Validator::isAadhar(std::string s) {
	if(s.length() !=12)
        	return false;
	for (int i = 0; i < (int)s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

bool Validator::isNumber(std::string s) {
	if(s.length() == 0)
		return false;
	for (int i = 0; i < (int)s.length(); i++)
                if (isdigit(s[i]) == false)
                        return false;
	return true;
}

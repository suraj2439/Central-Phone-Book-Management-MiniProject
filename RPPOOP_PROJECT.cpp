#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define NORMAL		0
#define VIP		1
#define LANDLINE_NO	2
#define MOBILE_NO	3
#define FIRST_DIGIT 	4
#define INSERT_NO	5
#define UPDATE_INFO	6
#define DEL_NO		7

using namespace std;

typedef struct info{
	char name[50]; 
	char email[50]; 
	char company[15];
}info;

// struct to store history
typedef struct hstry {
	time_t time;
	string num;
	int operation;
	info *info_H;
} hstry;

class node{
	private :
		node *parent, *n[10];
	protected :
		char c;
		info *inf;
	public :
		void init_node(){
			this->parent = NULL;
			int i;
			for(i=0;i<10;i++)
				this->n[i] = NULL;
		}
	friend class trie;
	friend void display_number_via_substring(node *nn,char *c);
};

class leaf_node: public node{
	private :
		int data;
		node *parent;
		static int count;
	
	public :
		void init_leaf_node(){
			int i;
			this->parent = NULL;
	}
	friend class trie;
};
      
class trie{
	private:
		
	public :	
		node *root;
		
		// constructor
		trie(){
			root = (node*)malloc(sizeof(node));
			root->parent = NULL;
			for(int i = 0;i<10;i++){
				root->n[i] = NULL;
			}
		}
		
		void insert_number(char *ch,int num){
			int k = num, i = ch[0] - '0', j = 0;
			node *p = root->n[i],*q = root, *n;
			leaf_node *l;
			while(p){                        // omitting entered part
				j++;
				i = ch[j] - '0';
				if(j == 8)
					p = (leaf_node*)p;
				if(j == 9)
					q = (leaf_node*)q;
				q = p;
				p = p->n[i];
			}
			if(k == 0)
				return;
			if(q == NULL)
				return;
			while(ch[j] != '\0'){
				printf("%c ",ch[j]);
				if(j != 9) {
					n = (node*)malloc(sizeof(node));
					n->init_node();
					i = ch[j] - '0';
					q->n[i] = n;
					n->c = i;
					n->parent = q;
					q = q->n[i];
				}
				
				else if(j == 9) {
					n = (leaf_node*)malloc(sizeof(leaf_node));
					n->init_node();
					i = ch[j] - '0';
					q->n[i] = (leaf_node*)q->n[i];
					q->n[i] = n;
					n->c = i;
					n->parent = q;					
				}
				j++;
			}
		}
		
		int is_present(char *ch){
			node *p = root;
			int i = 0,k;
			while(ch[i] != '\0') {
				k = ch[i] - '0';
				if(p->n[k] == NULL) {
					printf("NO");
					return 0;
				}
				if(i == 9)
					p->n[i] = (leaf_node*)p->n[i];
				p = p->n[k];
				i++;	
			}
			printf("YES");
			return 1;
		}
		
		void insert_info(char *ch,char *name,char *email,char *company) {
			node *p = root;
			leaf_node *q;
			int i = 0,k;
			while(ch[i] != '\0') {
				k = ch[i] - '0';
				if(p->n[k] == NULL) {
					return ;
				}
				if(i == 9){
					p->n[i] = (leaf_node*)p->n[i];
				}
				p = p->n[k];
		//		printf(" %d ",p->c);
				i++;	
			}	
			printf(" %d ",p->c);
			p->inf = (info*)malloc(sizeof(info));	
			strcpy(p->inf->name,name);
			strcpy(p->inf->email,email);
			strcpy(p->inf->company,company);	
		    printf("%s   %s   %s ",p->inf->name ,p->inf->email ,p->inf->company);
		}
		
		char* get_info(char *ch,int mode){
			node *p = root;
			int i = 0,k;
			while(ch[i] != '\0') {
				k = ch[i] - '0';
				if(p->n[k] == NULL) {
					return "HH";
				}
				if(i == 9)
					p->n[i] = (leaf_node*)p->n[i];
				p = p->n[k];
				printf(" %d ",p->c);
				i++;	
			}		
			if(mode == 1){
				printf(" %s ",p->inf->name);
				return p->inf->name;
			}
			else if(mode == 2){
				printf(" %s ",p->inf->email);
				return p->inf->email;
			}
			else if(mode == 3){
				printf(" %s ",p->inf->company);
				return p->inf->company;
			}
		}
		
		void delete_number(char *ch) {
			node *p = this->root,*q = this->root;
			int i = 0, k;
			while(ch[i] != '\0') {
				k = ch[i] - '0';
				q = p;
				p = p->n[k];
				i++;
			}
			p = q;
			printf("%dn",p->c);
			int cnt = 0;
			while(p != this->root){
				for(i=0;i<10;i++){
					if(p->n[i] != NULL)
						cnt++;
				}
				if(cnt > 1)
					return;
				q  = p;
				p = p->parent;
				k = q->c;
				printf(" %d ",q->c);
				delete q->n[k];
				p->n[k] = NULL;
			}
		}
		
		friend void display_number_via_substring(node *nn,char *c);
};



// class containing functions to store and retrive 
// history of operations perforemd
class History {
	private:
		// variable to store base time(reference) at start
		time_t base_time;

		// vector to store history
		vector<hstry> history;

		// func to apply lower bound on vector history using binary search, 
		// as data will be in sorted form due to non decreasing timestamp
		int binary_search(vector<hstry> his, time_t time) {
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

	public:
		// constructor use to init base_time to maintain history
		History() {
			time(&base_time);
		}

		// func to return current time
		// time will be stored as number of seconds elapsed from init of constructor of History
		time_t get_time() {
                        return time(NULL) - base_time;
                }

		// func to store history history of operation
		void store_history(string num, int operation) {
			hstry h;
			h.time = time(NULL) - base_time;	
			h.num = num;
			h.operation = operation;
			h.info_H = NULL;

			history.push_back(h);
			return;
		}

		// func overloading , use to store history of operation
		void store_history(string num, int operation, info Inf) {
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
		vector<hstry> retrive() {
                        vector<hstry> res = history;
                        return res;
                }

		// func to retrive N units of history from given time
		vector<hstry> retrive(time_t time, int N) {
			vector<hstry> res;
			// apply lower bound for time
			int indx = binary_search(history, time);
			for(int i = 0; i < N, i < history.size(); i++)
				res.push_back(history[i]);

			return res;
		}

		// func to retrive history between two time time1 and time2, time1 < time2
		vector<hstry> retrive(time_t time1, time_t time2) {
                        vector<hstry> res;
			// applyl lower bound for time1
                        int indx = binary_search(history, time1);

                        for(int i = 0; i < history.size(), history[i].time <= time2; i++)
                                res.push_back(history[i]);

                        return res;
                }

		void print() {
			for(int i = 0; i < history.size(); i++)
				cout<<history[i].num<<endl;
			return;
		}

};





// class to wrap the functions which use to generate numbers based upon 
// type(mobile no, landline no) of number
// country code(for mobile no) and area code(for landline no)
// vip number(user can give last N digits, N <= 4)
class Generator {
	private:
		char getrandomdigit() {
			return (rand() % 10) + 48;
		}
		// function overloading
		char getrandomdigit(int flag) {
			return (6 + rand() % 4) + 48;
		}
	public:
		// func to generate number based on type(mobile no/ landline no) 
		// and counry code/area code
		string generate_number(int type, int country_or_area_code) {
			string result;
			result = result + to_string(country_or_area_code);
			int rem = 9;
			if(type == LANDLINE_NO)
				rem = 7;
			else result.push_back(getrandomdigit(FIRST_DIGIT));
			for(int i = 0; i < rem; i++)
				result.push_back(getrandomdigit());
			return result;
		}
	
		// func overloading, func use to generate vip number 	
		string generate_number(int type, int country_or_area_code, int size, int vip) {
			string res;
			res = res + to_string(country_or_area_code);
			int rem = 9 - size;
                        if(type == LANDLINE_NO)
                                rem = 7 - size;
                        else res.push_back(getrandomdigit(FIRST_DIGIT));
                        for(int i = 0; i < rem; i++)
                                res.push_back(getrandomdigit());
			res = res + to_string(vip);
			return res;
		}
};
	
void display_number_via_substring(node *nn,char *c);
	        

int main(){    
	string s;
	History h;
	Generator g;
	h.store_history(g.generate_number(MOBILE_NO, 91), INSERT_NO);
	h.store_history(g.generate_number(MOBILE_NO, 91), INSERT_NO);
	h.store_history(g.generate_number(MOBILE_NO, 91), INSERT_NO);

	while(h.get_time() != 3);

	h.store_history(g.generate_number(MOBILE_NO, 91), INSERT_NO);
	h.store_history(g.generate_number(MOBILE_NO, 91), INSERT_NO);

	vector<hstry> tmp;
	time_t t1 = 0, t2 = 2;
	tmp = h.retrive(t1, t2);

	for(int i = 0; i < tmp.size(); i++)
		cout<<tmp[i].num<<endl;

	//h.print();
	/*
	for(char i:)
		cout<<i;
	cout<<endl;

	for(char i:s)
                cout<<i;
        cout<<endl;

	//cout<<h.get_time()<<endl;
	//h.retrive(h.get_time());
	h.print();*/

	/*
	trie T;
	T.insert_number("9420047765",10);
	T.insert_number("9000047774",10);
	T.insert_number("9100047765",10);
	T.insert_number("9100047764",10);
	T.insert_number("4567890235",10);
	T.is_present("9100047765");
	T.insert_info("9420047765","Siddhesh","siddheshmehta13@gmail.com","bsnl");
	T.get_info("9420047765",1);
	T.is_present("9100047764");
	display_number_via_substring(T.root,"910");*/
	return 0;
}

//Derived<int> * d = static_cast<Derived<int>* >(b)

void display_number_via_substring(node* nn,char *number){
	
	//if present node is null
	if(nn == NULL)
		return;
	
	//if character not found then traverse forward
	if(number[0] - '0' != nn->c){
		int i;
		for(i=0;i<10;i++){
			display_number_via_substring(nn->n[i],number);
		}
		return;
	}
	
	//if first character matches
	int flag = 0;
	if(number[0] - '0' == nn->c){
		int len = strlen(number), i = len, k = 0;
		while(i != 0){
			if(nn->n[number[k++]-'0'] == NULL){
				printf("KK");
				flag = 1;
				break;
			}
			i--;
		}
	}
	
	if(flag == 1) {
	//	printf("NOT FOUND");
		int i;
		for(i=0;i<10;i++){
			display_number_via_substring(nn->n[i],number);
		}			
		return;
	}
	
	if(flag == 0){
		printf("FOUND");
	}
}


// insert vip number
// modify number or info
// event handling
// history



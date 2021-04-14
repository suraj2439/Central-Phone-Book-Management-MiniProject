#ifndef BACKEND_H
#define BACKEND_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>


#define NORMAL          0
#define VIP             1
#define MOBILE_NO       0
#define LANDLINE_NO     1
#define FIRST_DIGIT     4
#define INSERT_NO       5
#define UPDATE_INFO     6
#define DEL_NO          7
#define MAX_SUBSTRING	10


typedef struct info {
	std::string name;
	std::string email;
	std::string company;
}info;

// struct to store history
typedef struct hstry {
        time_t time;
	std :: string num;
        int operation;
        info *info_H;
} hstry;



class node{
	private :
		node *parent, *child[10];
	protected :
		char ch;
		info *inf;
	public :
	
	void init_node();
		
	friend class Trie;
	friend void take_number_via_substring(node *nn, std::string c);
	friend void take_prev(node *nn);
	friend void take_fwd(node *nn);
	friend void fill_vector(node *nn,std:: vector<char> v);
	friend void go_to_end(node *nn);
};

class leaf_node: public node{
	private :
		int ch;
		node *parent;
		static int count;
	public:
		
		void init_leaf_node();
		
 	friend class Trie;
};
  

class History {
        private:
		// used for frontend
                int historyPageNo;

                // variable to store base time(reference) at start
                time_t base_time;

                // vector to store history
                std :: vector<hstry> history;

                // func to apply lower bound on vector history using binary search,
                // as data will be in sorted form due to non decreasing timestamp
                int binary_search(std :: vector<hstry> his, time_t time);

                public:

                // constructor use to init base_time to maintain history
                History();

                // func to return current time
                // time will be stored as number of seconds elapsed from init of constructor of History
                time_t get_time();

                // func to store history history of operation
                void store_history(std :: string num, int operation);

                // func overloading , use to store history of operation
                void store_history(std :: string num, int operation, info Inf);

                // function to retrive all history
                std :: vector<hstry> retrive();

                // func to retrive N units of history from given time
                std :: vector<hstry> retrive(time_t time, int N);

                // func to retrive history between two time time1 and time2, time1 < time2
                std :: vector<hstry> retrive(time_t time1, time_t time2);

		void set_historyPageNo(int no);
		int get_historyPageNo();

                void print();

};



class Trie {
	private:
		History *history;
		
	public :	
		Trie();
		void insert_number(std::string num);
		int is_present(std::string num);
		void insert_info(std::string num,info* information);
		std::string get_info_one(std::string num,int mode);
		info* get_info(std::string num);
		void delete_number(std::string num);
		void traverse_directory();
		History get_history();
		
		node *root;

		friend void display_number_via_substring(node *nn, std::string c);
		friend void display_prev(node *nn,int i);
		friend void display_fwd(node *nn);
		friend void go_to_end(node *nn);
		friend void fill_vector(node *nn,std::vector<char> v);
};	  


class Generator {
        private:
                char getrandomdigit();

                // function overloading
                char getrandomdigit(int flag);

        public:
		Generator();
                // func to generate number based on type(mobile no/ landline no)
                // and counry code/area code
                std :: string generate_number(int type, int country_or_area_code);

		// func overloading, func use to generate vip number    
                std :: string generate_number(int type, int country_or_area_code, int size, int vip);

};


class Validator {
	private:

	public:
		//cheaks given number is valid or not
		bool isPhoneNumber(std::string s);

		//cheaks given name is valid or not
		bool isName(std::string s);
		
		//cheaks aadhar number is valid or not
		bool isAadhar(std::string s);

		bool isNumber(std::string s);
};

void display_number_via_substring(node *nn, std::string c);	
void display_prev(node *nn);
void display_fwd(node *nn);
void go_to_end(node *nn);
void fill_vector(node *nn,std::vector<char> v);
void store_vector_into_string();	


#endif           
  	

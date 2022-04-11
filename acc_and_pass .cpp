#include<iostream>
#include<string>
using namespace std;
 
struct account{
	string name;
	string pass;
	account* next;
};

class Store{
	account* top = NULL;
	public:
		void pop(string, string);
		account* search_com(string, string);
		void delete_acc(string);
};

void Store::pop(string acc, string pass){
	account* newacc = new account;
	newacc-> name = acc;
	newacc-> pass = pass;
	newacc-> next = top;
	top = newacc; 
}

account* Store::search_com(string acc, string pass){
	account* ptr = top;
	while(ptr != NULL){
		if(ptr-> name == acc){
			if(ptr-> pass == pass){
				cout << "login successful!!" << endl;
				return ptr;
			}
		}else{
			ptr = ptr-> next;
		}
	}
	count << "Wrong account or password!!" << endl;
	return NULL;
} 

void Store::delete_acc(string acc){
	account* ptr;
	while(ptr != NULL){
		if(ptr-> name == acc){
			string p;
			cout << "password: ";
			cin.ignore();
			cin >> p;
			if(p == ptr-> pass)
		}
	} 
}
 
int main()
{
    int act, pass, pk, key, account;
    Store* host = new Store;
    while(1){
		cout << "1. log in" << endl;
		cout << "2. sign in" << endl;
		cout << "3. delete account" << endl;
		cout << "0. EXIT" << endl;
		cin >> act
		if(act == 0) break;
		
		cout << "Enter account: ";
				cin.ignore();
				cin >> account;
				cout << "Enter password: ";
				cin.ignore();
				cin >> pass;
		switch(act){
			case 1:
				host-> pop(account, pass);
				break;
			case 2:
				host-> search_compare(pass);
				break;
			case 3:
				host-> delete_acc(acc);
				break;
		}
	}
 
}

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
		int search_com(string);
		void delete_acc(string, string);
};

void Store::pop(string acc, string pass){
	
}

int Store::search_com(string pass){
	
} 

void Store::delete_acc(string acc, string pass){
	
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
				host-> delete_acc(acc, pass);
				break;
		}
	}
 
}

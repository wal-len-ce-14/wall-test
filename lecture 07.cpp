#include<iostream>
using namespace std;
class Base{
	public:
		virtual void dis(){
			cout << "class Base" << endl;
		}
};

class Derive: public Base{
	public:
		void dis()override{
			cout << "class Derive" << endl;
		}
};

int main(){
	Base B;
	Derive D;
	Base *BB = &D;
	B.dis();
	D.dis();
	BB->dis (); 
	return 0;
}



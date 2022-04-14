#include<iostream>
using namespace std;

class Deck{
	private:
		int *n1 = new int[5];
		char *s1 = new char[5];
	public:
		Deck() = default;
		Deck(int* f, char* cf): n1(f), s1(cf){};
		friend int Estimate(Deck);
};

int main(){
	int *no = new int[5];
	char *suit = new char[5];
	int n, i, j, conti = 1;
	char c;
	while(conti){
		for(i = 0; i < 5; i++){
			cin >> c >> n; 
			suit[i] = c;
			no[i] = n;
		}
		Deck
	}
	return 0;
}










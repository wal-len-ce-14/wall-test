#include<iostream>
using namespace std;
int com_n(int*);
int com_c(char*);
int str(int*);

class Deck{
	private:
		int* cardno = new int[5];
		char* cardsuit = new char[5];
	public:
		Deck(int* no, char* su): cardno(no), cardsuit(su){};
		friend int compare(Deck F, Deck S);
		friend int size(Deck F, Deck S);
};

int compare(Deck F, Deck S){         //S, H, D, C
	int i, j, n, com[2];
	// for F
	if(com_c(F.cardsuit) == 5){
		if(str(F.cardno)){
			com[0] = 8;
		}
	}else if(com_n(F.cardno) == 4){
		com[0] = 7;
	}else if(str(F.cardno) == 2){
		com[0] = 6;
	}else if(str(F.cardno) == 1){
		com[0] = 5;
	}else if(com_n(F.cardno) == 3){
		com[0] = 4;
	}else if(str(F.cardno) == 3){
		com[0] = 3;
	}else if(com_n(F.cardno) == 2){
		com[0] = 2;
	}else{
		com[0] = 1;
	}
	//for S
	if(com_c(S.cardsuit) == 5){
		if(str(S.cardno)){
			com[1] = 8;
		}
	}else if(com_n(S.cardno) == 4){
		com[1] = 7;
	}else if(str(S.cardno) == 2){
		com[1] = 6;
	}else if(str(S.cardno) == 1){
		com[1] = 5;
	}else if(com_n(S.cardno) == 3){
		com[1] = 4;
	}else if(str(S.cardno) == 3){
		com[1] = 3;
	}else if(com_n(S.cardno) == 2){
		com[1] = 2;
	}else{
		com[1] = 1;
	}
	
	//compare
	if(com[0] > com[1]) return 1;
	else if(com[0] < com[1]) return 0;
	else {
		return size(F, S);
	}
}

int com_n(int* no){
	int i, j, max, cur, mo;
	for(i = 0; i < 5; i++){
		cur = 0;
		for(j = 0; j < 5; j++){
			if(no[i] == no[j]){
				cur++;
			}
		}
		if(max <= cur) {
			max = cur;
		}
	}
	return max;
}

int str(int* no){
	int cc[5];
	int i, j;
	int temp;
	
	for(i = 0; i < 5; i++){
		cc[i] = no[i];
	}
	
	for(i = 0; i < 5; i++){
		for(j = i; j < 5; j++){
			if(cc[i] < cc[j]){
				temp = cc[i];
				cc[i] = cc[j];
				cc[j] = temp;
			}
		}
	}
	
	if((cc[0] == cc[2] && cc[3] == cc[4])|| (cc[0] == cc[1] && cc[2] == cc[4])){
		return 2;
	}
	else if(cc[0] - cc[4] == 4) return 1;
	else if(cc[0] == cc[1] && cc[2] == cc [3] || cc[0] == cc[1] && cc[3] == cc[4] || cc[1] == cc[2] && cc[3] == cc[4]){
		return 3;
	}
	else return 0;
}



int size(Deck F, Deck S){
	int i, n, maxF = 0, maxS = 0, mf, ms;
	for(i = 0; i < 5; i++){
		if(maxF < F.cardno[i]){
			maxF = F.cardno[i];
			mf = i;
		}
	}
	for(i = 0; i < 5; i++){
		if(maxS < S.cardno[i]){
			maxS = S.cardno[i];
			ms = i;
		}
	}
	if(maxF > maxS) return 1;
	else if(maxF < maxS) return 0;
	else if(maxF == maxS){
		switch(F.cardsuit[mf]){					//S, H, D, C
			case 'S':
				mf = 4;
				break;
			case 'H':
				mf = 3;
				break;
			case 'D':
				mf = 2;
				break;
			case 'C':
				mf = 1;
				break;
			default:
				mf = 0;
				break;		
		}
		switch(S.cardsuit[ms]){					//S, H, D, C
			case 'S':
				ms = 4;
				break;
			case 'H':
				ms = 3;
				break;
			case 'D':
				ms = 2;
				break;
			case 'C':
				ms = 1;
				break;
			default:
				ms = 0;
				break;		
		}
		if(mf > ms) return 1;
		else if(mf < ms) return 0;
		else return -1;
	}
}

int com_c(char* su){
	int i, j, max, cur;
	for(i = 0; i < 5; i++){
		cur = 0;
		for(j = 0; j < 5; j++){
			if(su[i] == su[j]){
				cur++;
			}
		}
		if(max <= cur) max = cur;
	}
	return max;
}
 
main(){
	int* no = new int[5];
	char* su = new char[5];
	int answer[10];
  	int i, j, n, con = 0, tim = 0;
	cout << "enter the decks:" << endl;
	
	while(con == 0){
		
		for(i = 0; i < 5; i++){
			char c = getchar();
			su[i] = c;
			cin.ignore();	
			cin >> n;
			no[i] = n;
			cout << i << endl;
		}
		Deck D1(no, su);
		for(i = 0; i < 5; i++){
			char c = getchar();
			cin >> n;
			no[i] = n;
			su[i] = c;	
		}
		Deck D2(no, su);
		
		answer[tim] = compare(D1, D2);
		
		cout << "Do you want to continus? (1 yes / 0 no)" << endl;
		cin >> con;
		tim++;
	}
	for(i = 0; i < tim; i++){
		cout << answer[i] << endl;
	}
	return 0;
}






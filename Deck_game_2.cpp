#include<iostream>
using namespace std;
int esti(char*, int*);
int same_color(char*);
int straight(int*);
int same_no(int*);
int gourd(int*);
int two_pair(int*);
void _sort(int*);
double _max(int*);

int main(){
	int *no1 = new int[5];
	int *no2 = new int[5];
	char *su1 = new char[5];
	char *su2 = new char[5];
	int round[10];
	int n, i, j, conti = 1, p1, p2, r = 0;
	char c;
	while(conti){
		for(i = 0; i < 5; i++){
			cin >> c >> n;
			su1[i] = c;
			no1[i] = n;
		}
		for(i = 0; i < 5; i++){
			cin >> c >> n;
			su2[i] = c;
			no2[i] = n;
		}
		p1 = esti(su1, no1);
		p2 = esti(su2, no2);

		p1 = p1 + _max(no1);
		p2 = p2 + _max(no2);

		if(p1 > p2) round[r++] = 1;
		else if(p1 < p2) round[r++] = 0;
		else round[r++] = -1;

		cout << "Again?(1 yes / 0 no): " << endl;
		cin >> conti;
	}

	for(i = 0; i < r; i++){
        cout << round[i] << endl;
	}

	return 0;
}

int esti(char* suit, int* card){
    int i, n, p;
    if(same_color(suit) || straight(card)){
        p = 8;
    }else if(same_no(card) == 4){
        p = 7;
    }else if(gourd(card)){
        p = 6;
    }else if(straight(card)){
        p = 5;
    }else if(same_no(card) == 3){
        p = 4;
    }else if(two_pair(card)){
        p = 3;
    }else if(same_no(card) == 2){
        p = 2;
    }else p = 1;

    return p;
}

int same_color(char* suit){
    int i, j, n;
    for(i = 1; i < 5; i++){
        if(suit[0] != suit[i]) return 0;
    }
    return 1;
}

int straight(int* card){
    int i, j, n[5];
    for(i = 0; i < 5; i++){
        n[i] = card[i];
    }
    _sort(n);
    if(n[4] - n[0] == 4) return 1;
    else return 0;
}

int same_no(int* card){
    int i, j, n, m;
    m = 0;
    for(i = 0; i < 4; i++){
        n = 1;
        for(j = 1; j < 5; j++){
            if(card[i] == card[j]){
                n++;
            }
        }
        if(m < n) m = n;
    }
    return m;
}

void _sort(int* card){
    int i, j, n;
    for(i = 0; i < 4; i++){
        for(j = i+1; j < 5; j++){
            if(card[i] > card[j]){
                n = card[i];
                card[i] = card[j];
                card[j] = n;
            }
        }
    }
}

double _max(int* v){
    int i, Max = 0;
    for(i = 0; i < 5; i++){
        if(v[i] > Max){
            v[i] = Max;
        }
    }
    Max = Max / 100;
    return Max;
}









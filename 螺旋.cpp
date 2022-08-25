#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
void draw(int n, string str1);

int main(void){
    int n;
    string str1;

    cout << "����Ϊ������: ";
    cin >> n;
    cout << "�п�J�r��: ";
    cin.ignore();
    getline(cin,str1);
    draw(n,str1);
    return 0;

 }

 void draw(int n ,string str1){
    int i, j, st, t;
    char squ[n][n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            squ[i][j] = ' ';
        }
    }
    st = 0; t = 0;                             	// 1  2  3  4
                                                // 12 13 14 5
                                                // 11 16 15 6
                                                // 10 9  8  7
    for(i = 0, j = 0; j < n; j++, st++){
            if(str1[st] == '\0') st = 0;
            squ[i][j] = str1[st];
            cout << "\(" << i << "," << j << "\)" << endl;
    }
    i = 0; j--;
    while(t <= n){

        // r u -> d
        for(i++; i < n-t; i++, st++){
            if(str1[st] == '\0') st = 0;
            squ[i][j] = str1[st];
            cout << "\(" << i << "," << j  << "," << n-t << "\)" << endl;
        }
        i--;
        // d l -> r
        for(j--; j >= 0+t; j--, st++){
            if(str1[st] == '\0') st = 0;
            squ[i][j] = str1[st];
            cout << "\(" << i << "," << j  << "," << 0+t << "\)" << endl;
        }
        t++; j++;

        // l d -> u
        for(i--; i >= 0+t; i--, st++){
            if(str1[st] == '\0') st = 0;
            squ[i][j] = str1[st];
            cout << "\(" << i << "," << j << "," << 0+t << "\)" << endl;
        }
        i++;
        // u r -> l
        for(j++; j < n-t; j++, st++){

            if(str1[st] == '\0') st = 0;
            squ[i][j] = str1[st];
            cout << "\(" << i << "," << j << "," << n-t << "\)" << endl;
        }
        j--;
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << " " << squ[i][j];
        }
        cout << endl;
    }
 }









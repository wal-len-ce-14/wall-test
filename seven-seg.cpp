/*

          A__
       F|   B|
         G__
      E|   C|
        D__

  __
|   |
__
|   |
__
*/
#include<iostream>
using namespace std;

int seperate(int, int*);

int main(){
    int v[10] = {0};   //A, B, C, D, E, F, G
    int dsp[10][7] = {  {1, 1, 1, 1, 1, 1, 0},      // 0
                        {0, 1, 1, 0, 0, 0, 0},      // 1
                        {1, 1, 0, 1, 1, 0, 1},      // 2
                        {1, 1, 1, 1, 0, 0, 1},      // 3
                        {0, 1, 1, 0, 0, 1, 1},      // 4
                        {1, 0, 1, 1, 0, 1, 1},      // 5
                        {1, 0, 1, 1, 1, 1, 1},      // 6
                        {1, 1, 1, 0, 0, 0, 0},      // 7
                        {1, 1, 1, 1, 1, 1, 1},      // 8
                        {1, 1, 1, 1, 0, 1, 1}       // 9
                     };
    int i, j, n, row = 1;

    cin >> n;
    n = seperate(n, v);
    for(j = 0; j < 3; j++){
        for(i = n-1; i >= 0; i--){
            switch(j){
                case 0:
                    if(dsp[v[i]][0]) cout << "  __ ";
                    else cout << "     ";
                    break;
                case 1:
                    if(dsp[v[i]][5]) cout << " |";
                    else cout << "  ";

                    if(dsp[v[i]][6]) cout << "__";
                    else cout << "  ";

                    if(dsp[v[i]][1]) cout << "|";
                    else cout << " ";
                    break;
                case 2:
                    if(dsp[v[i]][4]) cout << " |";
                    else cout << "  ";

                    if(dsp[v[i]][3]) cout << "__";
                    else cout << "  ";

                    if(dsp[v[i]][2]) cout << "|";
                    else cout << " ";
                    break;
            }
        }
        cout << endl;
    }


   /* for(i = 0; i < n; i++){
        cout << v[i] << endl;
    }*/

    return 0;
}

int seperate(int n, int* v){
    int d = 10, k = 0;
    while(d){
        if(n % d){
            v[k++] = n%d;
        }else return k;

        n = n / d;
    }
}

#include <iostream>
#include <windows.h>
using namespace std;

int *getSkyline(int*);

int main(){
	int n, i, j, buildings[100][3] = {0};

	for(i = 0; i < 100; i++){
        for(j = 0; j < 3; j++){
            buildings[i][j] = 0;
        }
	}

	for(i = 0; i < 100; i++){
        for(j = 0; j < 3 && cin >> buildings[i][j]; j++);
	}


    int *sky = getSkyline(&buildings[0][0]);
    cout << "10" << endl;
    for(i = 0; i < 100 && *(sky+2*i+0) + *(sky+2*i+1) != 0; i++){
        for(j = 0; j < 2; j++){
            cout << *(sky+2*i+j) << " ";
        }
        cout << endl;
    }

    return 0;
}

int *getSkyline(int* buildings){
    int x, y, i, j, buil, current = -1, s;
    int* sky = new int[100];
    for(i = 0; i < 100; i++){
        *(sky+i) = 0;
    }
    x = -1; y = 0;            //水平座標, 垂直座標
    buil = 0;
    s = 0;
    while(true){

        int _y = y;
        x++;
        //cout << "1" << endl;
        if(x == *(buildings+3*buil+0)){

            if(y < *(buildings+3*buil+2) && (current < 0 || *(buildings+3*current+0) < *(buildings+3*buil+0))){
                y = *(buildings+3*buil+2);
                current = buil;
              //  cout << "2" << endl;
            }
            buil++;
        }
        //cout << "3" << endl;
        if(x == *(buildings+3*current+1) && current >= 0){

        //cout << "4" << endl;
            int _max = 0;
            int tem = -1;
            for(i = 0; i < 100 && *(buildings+3*current+1) >= *(buildings+3*i+0); i++){
                if(*(buildings+3*current+1) < *(buildings+3*i+1)){
                    if(*(buildings+3*i+2) > _max){
                        _max = *(buildings+3*i+2);
                        tem = i;
                    }
                }
            }
            y = _max;
            current = tem;

        }
        //cout << "5" << endl;
        if(_y != y){
        //cout << "6" << endl;
            *(sky+2*s+0) = x;
            *(sky+2*s+1) = y;
            s++;
        }

//cout << "7" << endl;

        if(y == 0 && *(buildings+3*buil+2) == 0){

       // cout << "8" << endl;
            break;
        }
        //cout << "9" << endl;
    }
    return sky;
}








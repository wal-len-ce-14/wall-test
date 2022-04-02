#include <iostream>
#include <windows.h>
using namespace std;

int **getSkyline(int**);

int main(){
	int _count, n, i = 0, j = 0, buildings[20][3];  /// [left.i, right.i, height.i]

	for(i = 0; i < 20; i++){
		for(j = 0; j < 3; j++){
			buildings[i][j] = -1;
		}
	}
    j = 0;
	cout << "How many buildings are there? ";
	cin >> _count;
	cout << "Enter the buildings: ";
	while(_count != 0){
		for(i = 0; i < 3; i++){
			cin >> n;
			buildings[j][i] = n;
		}
		j++;
		_count--;
	}

	int *a = buildings[0];
	int* sky = getSkyline(&a)[0];
	int** skyline = &sky;
	n = j;
	for(j = 0; j < 20; j++){
        if(skyline[j][i] == 0) break;
		for(i = 0; i < 2; i++){
			cout << skyline[j][i] << "  ";
		}
		cout << endl;
	}
	return 0;
}

int **getSkyline(int** buildings){

	int i = 0, j = 0, buil = 0, lay = 0, max_H = 0, sky[20][2] = {0}, x = 0, tem = 0;
	while(true){
        cout << x << buildings[lay][1] << endl;
            system("pause");
        if(x == buildings[buil][0] && max_H < buildings[buil][2] && buildings[buil][1] > ){
            sky[i][0] = x;
            sky[i][1] = buildings[buil][2];
            max_H = buildings[buil][2];
            lay = buil;
            buil++;
            i++;


        }else if(x == buildings[buil][0]){
        	buil++;
		}


		if(x == buildings[lay][1]){
            cout <<buildings[j][0] << " " << buildings[lay][1] << endl;
            system("pause");
            max_H = 0;
            for(j = 0; j < 20 && buildings[j][0] < buildings[lay][1] && buildings[j][2] > 0; j++){
                if(buildings[j][1] > buildings[lay][1] && max_H < buildings[j][2]){
                    max_H = buildings[j][2];
                    tem = j;
                }
            }
            if(max_H > 0){
                sky[i][0] = x;
                sky[i][1] = max_H;
                lay = tem;
                i++;
                buil++;
            }else{
                sky[i][0] = x;
                sky[i][1] = max_H;
                i++;
                buil++;
            }
            cout << lay << " " << buildings[buil][2] << endl;
            system("pause");
            if(buildings[buil][2] < 0) break;
        }


        x++;
	}


	int *s = sky[0];
	return &s;
}




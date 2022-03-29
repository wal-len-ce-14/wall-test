#include <iostream>
using namespace std;

int **getSkyline(int**);

int main(){
	int count, n, i = 0, j = 0, buildings[20][3] = {-1};  /// [left.i, right.i, height.i]
	cout << "How many buildings are there? ";
	cin >> count;
	cout << "Enter the buildings: ";
	while(count--){
		for(i = 0; i < 3; i++){
			cin >> n;
			buildings[j][i] = n;
		}
		j++;
	}
	cout << "sd";
	int *a = buildings[0];
	int* sky = getSkyline(&a)[0];
	int** skyline = &sky;
	n = j;
	for(j = 0; j < n; j++){
		for(i = 0; i < 2; i++){
			cout << skyline[j][i] << "  ";
		}
		cout << endl;
	}
	return 0;
}

int **getSkyline(int** buildings){
	int i = 0, j, buil = 0, lay, max_H = 0, sky[20][2] = {0}, x = 0, tem;
	while(true){
        if(x == buildings[buil][0] && max_H < buildings[buil][2]){
            sky[i][0] = x;
            sky[i][1] = buildings[buil][2];
            max_H = buildings[buil][2];
            lay = buil;
            buil++;
            i++;
        }else if(x == buildings[lay][1]){
            max_H = 0;
            for(j = 0; j < 20, buildings[j][0] < buildings[lay][1], buildings[j][2] > 0; j++){
                if(buildings[j][1] > buildings[lay][1] && max_H < buildings[j][2]){
                    max_H = buildings[j][2];
                    tem = j;
                }
            }
            if(max_H != 0){
                sky[i][0] = x;
                sky[i][1] = max_H;
                lay = tem;
                i++;
                buil = lay+1;
            }else{
                sky[i][0] = x;
                sky[i][1] = max_H;
                i++;
                buil = j;
            }
        }

        if(buildings[buil][2] < 0){
            break;
        }

        x++;
	}


	int *s = sky[0];
	return &s;
}




#include <iostream>
using namespace std;

int **getSkyline(int**);

int main(){
	int count, n, i = 0, j = 0, buildings[10][3] = {-1};  /// [left.i, right.i, height.i]
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
	int *a = buildings[0];
	int** skyline = getSkyline(&a);
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
	int i, j = 0, k = 0, n[20][2] = {0}, lay = 0, max_H = 0;
	for(i = 0; i < 1000; i++){   
		cout << "10101\n";
		if(buildings[j][2] < 0){
			break;
		}
		if(i == buildings[j][0]){
			if(buildings[j][2] > max_H){
				n[k][0] = buildings[j][0];
				n[k][1] = buildings[j][2];
				max_H = buildings[j][2];
				lay = j;
				j++;
				k++;
			}else if(buildings[j][2] < max_H && buildings[j][1] > buildings[lay][1]){
				n[k][0] = buildings[lay][1];
				n[k][1] = buildings[j][2];
				max_H = buildings[j][2];
				lay = j;
				j++;
				k++;
				if(buildings[j][0] > buildings[lay][1]){
					n[k][0] = buildings[lay][1];
					n[k][1] = 0;
					max_H = 0;
					lay = 0;
					k++;
				}
			}else j++;
		}		
	}
	int *v = n[0]; 
	return &v;
}




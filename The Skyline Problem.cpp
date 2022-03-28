#include <iostream>
using namespace std;

int **getSkyline(int**);

int main(){
	int count, n, i = 0, j = 0, buildings[10][3] = {0};  /// [left.i, right.i, height.i]
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
		for(i = 0; i < 3; i++){
			cout << buildings[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}

int **getSkyline(int** buildings){
	int i, j = 0, n[20][2] = {0}, count, lay;
	for(i = 0;;i++){
		if(i = buildings[j][0]){
			n[j][0] = buildings[j][0];
			n[j][1] = buildings[j][2];
		}
		if()		
	}
}




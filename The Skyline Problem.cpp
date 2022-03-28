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
	
	int** skyline = getSkyline(buildings);
	
	n = j;
	for(j = 0; j < n; j++){
		for(i = 0; i < 3; i++){
			cout << buildings[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}

int *getSkyline(int* buildings){
	int i, n = buildings[0][0];
}

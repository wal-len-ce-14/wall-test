#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
#define W 60
#define H 40

int main(){
	int i, j, k, l, x, y, nl, nd, con = 0;
	int platform[W][H], l_point[W*H][2] = {0}, d_point[W*H][2] = {0};    //point (i, j)
	for(i = 0; i < H; i++){
		for(j = 0; j < W; j++){
			platform[i][j] = 0;
			cout << platform[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Enter the point" << endl;
	 srand(time(0));
	 int ccc = 0;
	while(ccc < W*H / 2){           //cin >> x >> y
        ccc++;
        x = rand() % W;
        y = rand() % H;
		platform[y][x] = 1;
	}

	system("pause");
	system("cls");

	while(1){
        nl = 0; nd = 0;
        l_point[W*H][2] = {0}; d_point[W*H][2] = {0};
        for(i = 0; i < H; i++){
            for(j = 0; j < W; j++){
                //cout << platform[i][j] << " ";
                if(platform[i][j]) cout << "o ";
                else cout << "  ";
            }
            cout << endl;
        }

		for(i = 0; i <= H-1; i++){
			for(j = 0; j <= W-1; j++){
                if(platform[i][j]){
                    con = 0;
                    for(k = i-1; k <= i+1 && k < H; k++){
                        for(l = j-1; l <= j+1 && l < W; l++){
                            if(k < 0) k++; if(k >= H-1) break;
                            if(l < 0) l++; if(l >= W-1) break;
                            if(platform[k][l]) con++;
                        }
                    }
                    switch(con){
                        case 0: case 1: case 2:
                            d_point[nd][0] = i;
                            d_point[nd][1] = j;
                            nd++;
                            break;
                        case 5: case 6: case 7: case 8: case 9:
                            d_point[nd][0] = i;
                            d_point[nd][1] = j;
                            nd++;
                            break;
                        default:
                            break;
                    }
                }else if(platform[i][j] == 0){
                    con = 0;
                    for(k = i-1; k <= i+1 && k < H; k++){
                        for(l = j-1; l <= j+1 && l < W; l++){
                            if(k < 0) k++;
                            if(k >= H-1) break;
                            if(l < 0) l++;
                            if(l >= W-1) break;
                            if(platform[k][l]) {con++;}// cout << k << " " << l<< endl;}
                        }
                    }
                    if(con == 3){
                        l_point[nl][0] = i;
                        l_point[nl][1] = j;
                        nl++;
                    }
                }
			}
		}
		for(i = 0; i <= nd-1; i++){
            platform[ d_point[i][0] ][ d_point[i][1] ] = 0;
		}
		for(i = 0; i <= nl-1; i++){
            platform[ l_point[i][0] ][ l_point[i][1] ] = 1;
		}


		Sleep(200);
		//system("pause");
		system("cls");
	}
	return 0;
}

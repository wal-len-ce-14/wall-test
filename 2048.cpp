#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>

#define Width 4
#define Height 4
void swapped(int* a, int* b);
void add(int* zero, int* sum);
int digit(int num);
int power(int base, int p);
bool is_move(char drc);
void animate(int* num, int* k_move);

int main(){
        /**************
           Game Set
        ***************/
    int i, j, k;
    int x, y;
    int is_add;
    int k_move[Height][Width];
    int num[Height][Width];
    for(i = 0; i < Height; i++){
        for(j = 0; j < Width; j++) num[i][j] = 0;
    }
    char drc = ' ';
    bool game = true;
    srand(time(NULL));

        /**************
           Game Loop
        ***************/
    while(game){


        /***************
            Generate
        ****************/
        if(is_move(drc) || drc == ' '){
            k = 0;
            do{
                k++;
                x = rand() % Width;
                y = rand() % Height;
                if(k > 20) break;
            }while(num[y][x] != 0);
            if(num[y][x] == 0) num[y][x] = 2;
        }

        /**************
            Display
        ***************/
        std::cout << std::endl;
        for(i = 0; i < Height; i++){
            std::cout << "  ";
            for(j = 0;j < Width; j++){
                std::cout << num[i][j];
                for(k = 0; k < 6-digit(num[i][j]); k++){
                    std::cout << " ";
                }

            }
            std::cout << std::endl << std::endl;
        }

        /*************
            Senser
        **************/
        drc = getch();
        k_move[Height][Width] = {0};
        switch(drc){
            case 'd':
                for(i = 0; i < Height; i++){
                    k = 0;
                    is_add = 1;
                    for(j = Width-1; j >= 0; j--){
                        if(num[i][j] == 0) k++;
                        else if(num[i][j] != 0){
                            swapped(&num[i][j], &num[i][j+k]);
                            k_move[i][j] = k;
                            if(num[i][j+k] == num[i][j+k+1] && j+k != Width-1 && is_add){
                                add(&num[i][j+k], &num[i][j+k+1]);
                                k++; is_add = 0;
                                k_move[i][j]++;
                            }else if(is_add == 0) is_add = 1;
                        }
                    }
                }
                break;
            case 'a':
                for(i = 0; i < Height; i++){
                    k = 0;
                    is_add = 1;
                    for(j = 0; j < Width; j++){
                        if(num[i][j] == 0) k++;
                        else if(num[i][j] != 0){
                            swapped(&num[i][j], &num[i][j-k]);
                            if(num[i][j-k] == num[i][j-k-1] && j-k != 0 && is_add){
                                add(&num[i][j-k], &num[i][j-k-1]);
                                k++; is_add = 0;
                            }else if(is_add == 0) is_add = 1;
                        }
                    }
                }
                break;
            case 'w':
                for(j = 0; j < Width; j++){
                    k = 0;
                    is_add = 1;
                    for(i = 0; i < Height; i++){
                        if(num[i][j] == 0) k++;
                        if(num[i][j] != 0){
                            swapped(&num[i][j], &num[i-k][j]);
                            if(num[i-k][j] == num[i-k-1][j] && i-k != 0 && is_add) {
                                add(&num[i-k][j], &num[i-k-1][j]);
                                k++; is_add = 0;
                            }else if(is_add == 0) is_add = 1;
                        }
                    }
                }
                break;
            case 's':
                for(j = 0; j < Width; j++){
                    k = 0;
                    is_add = 1;
                    for(i = Height-1; i >= 0; i--){
                        if(num[i][j] == 0) k++;
                        else if(num[i][j] != 0){
                            swapped(&num[i][j], &num[i+k][j]);
                            if(num[i+k][j] == num[i+k+1][j] && i+k != Height-1 && is_add) {
                                add(&num[i+k][j], &num[i+k+1][j]);
                                k++; is_add = 0;
                            }else if(is_add == 0) is_add = 1;
                        }
                    }
                }
                break;
            default:
                break;
        }
        system("cls");
    }
    return 0;
}

void swapped(int* a, int* b){
    if(*a == 0 || *b == 0){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void add(int* zero, int* sum){
    *sum += *zero;
    *zero = 0;
}

int digit(int num){
    int i, k;
    //if(num % 10 == 0) return 1;
    for(i = 10, k = 1; i <= power(10, 6); i *= 10, k++){
        if(num % i == num) return k;
    }
    return 0;
}

int power(int base, int p){
    int i, num;
    num = base;
    if(p == 0) return 0;
    if(p == 1) return base;
    for(i = 2; i <= p; i++){
        num = num * base;
    }
    return num;
}

bool is_move(char drc){
    if(drc == 'a' || drc == 's' || drc == 'd' || drc == 'w') return true;
    else return false;
}

/*void animate(int* num, int* k_move){
    int i, j, k, c;
    std::cout << std::endl;
    for(i = 0; i < Height; i++){
        std::cout << "  ";
        for(j = 0;j < Width; j++){
            std::cout << num[i][j];
            for(k = 0; k < 6-digit(num[i][j]); k++){
                std::cout << " ";
            }

        }
        std::cout << std::endl << std::endl;
    }
}*/

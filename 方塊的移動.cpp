#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class player{
    int i, j;
    public:

        int width, height, x, y;

        void display(void){
            for(i = 0; i < height+y; i++){
                if(i < y) cout << " ";
                else{
                    for(j = 0; j < width+x; j++){
                        if(j < x){
                            cout << "  ";
                        }else cout << "¡¼";

                    }
                }
                cout << endl;
            }
        }
        void moved(char c);
};

void player::moved(char c){
    switch(c){
        case 'd':
            x++;
            break;
        case 'a':
            x--;
            break;
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
    }
}

int main(){
    int i;
    char c;
    player Obj;
    Obj.x = 10;
    Obj.y = 5;
    while(1){
        Obj.width = 3;
        Obj.height = 3;
        Obj.display();
        for(i = 0;i < 20-Obj.y; i++) cout << endl;
        c = getch();
        Obj.moved(c);
        Sleep(100);
        system("cls");
    }
    return 0;
}

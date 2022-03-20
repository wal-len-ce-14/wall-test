#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
#define WIDTH 30
#define HEIGHT 20

void title(string start){
    int i, j;
    for(i = 0; i < 10; i++){
        cout << endl;
    }
    for(j = 0; j < WIDTH/2; j++){
        cout << " ";
    }
    cout << start << endl;
    for(i = 0; i < 10; i++){
        cout << endl;
    }
}

class Block{
    private:
        int i, j, _size = 2;
    public:
        int color_type = 0, degree = 0, x, y;

        void display(void){
            for(i = 0; i < HEIGHT; i++){
                if()
            }
        }


};

int main(){

//init
    title("Press the space start");
    getch();
    bool running = true;

//Object
    Block figure;
    figure.x = WIDTH/2;
    figure.y = 0;

//game
    while(running){

    }

    return 0;
}

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
//class Game{
//    private:
//
//        int SCREEN_WIDTH, SCREEN_HEIGHT;
//        int Table_wh, Table_ht, Table_x, Table_y;
//        char *screen;
//
//        HANDLE hCon;
//
//    public:
//
//        Game(int w, int h, int Tw int Th): SCREEN_WIDTH(w), SCREEN_HEIGHT(h), Table_wh(Tw), Table_ht(Th) { screen = new char[SCREEN_WIDTH*SCREEN_HEIGHT]; }
//        set_screen(int w, int h);
//};
//
//void Game::set_screen(int w, int h){
//    SCREEN_WIDTH = w;
//    SCREEN_HEIGHT = h;
//}
//
//Game *init_Screen(int width = 64, int height = 36, int Tw = 10, int Th = 20){
//    Game newgame(width, height, Tw, Th);
//
//}

int SCREEN_WIDTH = 40, SCREEN_HEIGHT = 30;
int Table_wh = 12, Table_ht = 22;

int Table_x = SCREEN_WIDTH/2 - Table_wh/2;
int Table_y = SCREEN_HEIGHT/2 - Table_ht/2;

char *screen = new char[SCREEN_WIDTH*SCREEN_HEIGHT];
int *pField = new int[Table_wh*Table_ht];
string tetromino[7];

int Rotate(int px, int py, int r, char opt = 'F'){
    if(opt == 'F'){
        switch(r){
            case 0: return py*4 + px;
            case 1: return 12 + py - (px*4);
            case 2: return 15 - py*4 - px;
            case 3: return 3 - py + px*4;
        }
    }
}

bool noCollide(int posi_x, int posi_y, int r, int Tetromino){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            int pi = Rotate(j, i, r);
            int fi = (posi_y+i) * Table_wh + (posi_x+j);

            if(tetromino[Tetromino][pi] == 'X'){
                    cout << pField[fi];
                if(posi_y+i < 0 || posi_y+i >= Table_ht || posi_x+j < 0 || posi_x+j >= Table_wh){
                    return false;
                }
                if(pField[fi] != ' '){
                    return false;
                }
            }
        }
    }


    return true;
}

int main(){
    int x, y, i, j;
    int r = 0;
    int posi_x, posi_y;

    //tetromino[0].append("F");
    tetromino[0].append("..X.");        // I
    tetromino[0].append("..X.");
    tetromino[0].append("..X.");
    tetromino[0].append("..X.");

    //tetromino[1].append("F");
    tetromino[1].append("....");        // O
    tetromino[1].append(".XX.");
    tetromino[1].append(".XX.");
    tetromino[1].append("....");

    //tetromino[2].append("T");
    tetromino[2].append("....");        // T
    tetromino[2].append(".XXX");
    tetromino[2].append("..X.");
    tetromino[2].append("....");

    //tetromino[3].append("T");
    tetromino[3].append("....");        // J
    tetromino[3].append("..X.");
    tetromino[3].append("..X.");
    tetromino[3].append(".XX.");

    //tetromino[4].append("T");
    tetromino[4].append("....");        // L
    tetromino[4].append(".X..");
    tetromino[4].append(".X..");
    tetromino[4].append(".XX.");

    //tetromino[5].append("T");
    tetromino[5].append("....");        // S
    tetromino[5].append("..XX");
    tetromino[5].append(".XX.");
    tetromino[5].append("....");

    //tetromino[6].append("T");
    tetromino[6].append("....");        // Z
    tetromino[6].append("XX..");
    tetromino[6].append(".XX.");
    tetromino[6].append("....");

    HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
    SetConsoleActiveScreenBuffer(hCon);
    DWORD dwBytesWritten = 0;

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.dwFontSize.X = 20;
    cfi.dwFontSize.Y = 22;
    SetCurrentConsoleFontEx(hCon, false, &cfi);

    for(i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++){
        screen[i] = ' ';
    }



    for(i = 0; i < Table_ht; i++){
        for(j = 0; j < Table_wh; j++){
            pField[i*Table_wh + j] = (j == 0 || j == Table_wh || i == 0 || i == Table_ht) ? 9 : 0;
        }
    }

    clock_t base = clock();
    clock_t now = clock();
    bool tm = false;
    bool GAME = true;
    int CurrentPiece = 6;
    posi_x = Table_wh/2-2;
    posi_y = 0;
    bool Key[4];

    while(GAME){
        // GAME TIMEING
        now = clock();
        if(now - base == 100){
            tm = true;
            base = now;
        }
        // INPUT
        if(tm){
            for(i = 0; i < 4; i++){                              //   R   L   D   U
                Key[i] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[i])));
            }
        }

        // GAME LOGIC
        if(Key[0]){
            if(noCollide(posi_x+1, posi_y, r, CurrentPiece)){
                posi_x += 1;
            }//else GAME = false;
        }
        if(Key[1]){
            if(noCollide(posi_x-1, posi_y, r, CurrentPiece)){
                posi_x -= 1;
            }
        }
        // RENDER OUTPUT

        // DRAW FIELD

        for(i = 0; i < SCREEN_HEIGHT; i++){
            for(j = 0; j < SCREEN_WIDTH; j++){
                screen[ (i+Table_y)*SCREEN_WIDTH + (j+Table_x) ] = " ABCDEFG=O"[ pField[i*SCREEN_WIDTH + j] ];
            }
        }




        for(i = 0; i < SCREEN_HEIGHT; i++){
            for(j = 0; j < SCREEN_WIDTH; j++){
                if((i == Table_y-1 || i == Table_y+Table_ht) && (j >= Table_x-1 && j <= Table_x+Table_wh)) screen[i*SCREEN_WIDTH + j] = 'O';
                else if((j == Table_x-1 || j == Table_x+Table_wh) && (i > Table_y-1 && i < Table_y+Table_ht)) screen[i*SCREEN_WIDTH + j] = 'O';
            }
        }
        // Draw Current piece

        for(i = 0; i < 4; i++){
            for(j = 0;j < 4; j++){
                if(tetromino[CurrentPiece][ Rotate(j, i, r) ] == 'X')
                    screen[(posi_y+i+Table_y) * SCREEN_WIDTH + (posi_x+j+Table_x)] = CurrentPiece + 65;
            }
        }
        tm = false;
        WriteConsoleOutputCharacter(hCon, screen, SCREEN_WIDTH*SCREEN_HEIGHT, {0,1}, &dwBytesWritten);
    }

    return 0;
}

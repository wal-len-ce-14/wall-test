#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

int SCREEN_WIDTH = 40, SCREEN_HEIGHT = 30;
int Table_wh = 12, Table_ht = 22;

int Table_x = SCREEN_WIDTH/2 - Table_wh/2;
int Table_y = SCREEN_HEIGHT/2 - Table_ht/2+1;

char *screen = new char[SCREEN_WIDTH*SCREEN_HEIGHT];
int *pField = new int[Table_wh*Table_ht];
std::string tetromino[7];

int Rotate(int px, int py, int r, char opt = 'F'){
    if(opt == 'F'){
        switch(r % 4){
            case 0: return py*4 + px +1;
            case 1: return 12 + py - (px*4) +1;
            case 2: return 15 - py*4 - px +1;
            case 3: return 3 - py + px*4 +1;
        }
    }else if(opt == 'T'){
        switch(r % 4){
            case 0: return py*4 + px +1;
            case 1:
                if(!px) return py +1;
                else return 12 + py - (px-1)*4 +1;
            case 2:
                if(!px || !py) return px + 4*py +1;
                else return 15 - (py-1)*4 - (px-1) +1;
            case 3:
                if(!py) return 4*px +1;
                else return 3 - (py-1) + px*4 +1;
        }
    }else return py*4 + px +1;
}

bool noCollide(int px, int py, int r, int Tetromino){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            int pi = Rotate(j, i, r, tetromino[Tetromino][0]);
            int fi = (py+i) * Table_wh + (px+j);

            if(tetromino[Tetromino][pi] == 'X' && pField[fi] != 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int i, j, px, py;
    int r;

    tetromino[0].append("F");
    tetromino[0].append("..X.");        // I
    tetromino[0].append("..X.");
    tetromino[0].append("..X.");
    tetromino[0].append("..X.");

    tetromino[1].append("F");
    tetromino[1].append("....");        // O
    tetromino[1].append(".XX.");
    tetromino[1].append(".XX.");
    tetromino[1].append("....");

    tetromino[2].append("T");
    tetromino[2].append("....");
    tetromino[2].append("....");        // T
    tetromino[2].append(".XXX");
    tetromino[2].append("..X.");


    tetromino[3].append("T");
    tetromino[3].append("....");        // J
    tetromino[3].append("..X.");
    tetromino[3].append("..X.");
    tetromino[3].append(".XX.");

    tetromino[4].append("T");
    tetromino[4].append("....");        // L
    tetromino[4].append(".X..");
    tetromino[4].append(".X..");
    tetromino[4].append(".XX.");

    tetromino[5].append("T");
    tetromino[5].append("....");
    tetromino[5].append("....");        // S
    tetromino[5].append("..XX");
    tetromino[5].append(".XX.");

    tetromino[6].append("T");
    tetromino[6].append("....");
    tetromino[6].append("....");        // Z
    tetromino[6].append(".XX.");
    tetromino[6].append("..XX");


    /// Set Console information

    HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
    SetConsoleActiveScreenBuffer(hCon);
    DWORD dwBytesWritten = 0;

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.dwFontSize.X = 20;
    cfi.dwFontSize.Y = 22;
    SetCurrentConsoleFontEx(hCon, false, &cfi);
    SetConsoleTitle("Wall Game --Tetris");
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = false;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hCon, &cci);
    std::vector<int> vLine;

    /// initialization

    for(i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++){
        screen[i] = ' ';
    }
    for(i = 0; i < Table_ht; i++){
        for(j = 0; j < Table_wh; j++){
            pField[i*Table_wh + j] = (i == 0 || i == Table_ht-1 || j == 0 || j == Table_wh-1) ? 9:0;
        }
    }
    srand(time(NULL));
    clock_t base = clock();
    clock_t now = clock();
    bool tm = false;
    bool GAME = true;
    bool Key[4];
    int CurrentPiece = rand() % 7;
    px = Table_wh/2-1;
    if(CurrentPiece == 0) py = 1;
    else if(CurrentPiece == 1 || CurrentPiece == 3 || CurrentPiece == 4) py = 0;
    else py = -1;
    r = 0;
    int nSpeed = 300;
    int nSpeedCount = 0;
    bool forceDown = false;
    bool KeyLock = true;
    int nScore = 0;
    bool KeyDown[3];
    for(i = 0; i < 3; i++) KeyDown[i] = true;
z    /// Game loop

    while(GAME){

        /// Timeing

        //Sleep(70);
        now = clock();
        if(now - base > nSpeed){
            nSpeedCount++;
            forceDown = true;
            base = now;
        }
//        if(nSpeed % 10 == 0 || nSpeed >= 100){
//            nSpeed -= 2;
//        }

        /// Input

        for(i = 0; i < 4; i++){                              //   R   L   D
            Key[i] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[i])));
        }

        /// GAME LOGIC


        if(Key[0]){
            px += (KeyDown[0] && noCollide(px+1, py, r, CurrentPiece)) ? 1:0;
            KeyDown[0] = false;
        }else KeyDown[0] = true;
        if(Key[1]){
            px -= (KeyDown[1] && noCollide(px-1, py, r, CurrentPiece)) ? 1:0;
            KeyDown[1] = false;
        }else KeyDown[1] = true;
        if(Key[2]){
            py += (KeyDown[2] && noCollide(px, py+1, r, CurrentPiece)) ? 1:0;
            KeyDown[2] = false;
        }else KeyDown[2] = true;



        if(Key[3]){
            r += (KeyLock && noCollide(px, py, r+1, CurrentPiece)) ? 1:0;
            KeyLock = false;
        }else KeyLock = true;


        if(forceDown){
            if(noCollide(px, py+1, r, CurrentPiece)){
                py += 1;
            }else{
                // lock
                for(i = 0; i < 4; i++){
                    for(j = 0; j < 4; j++){
                        if(tetromino[CurrentPiece][Rotate(j, i, r, tetromino[CurrentPiece][0])] == 'X'){
                            pField[(py+i)*Table_wh + px+j] = CurrentPiece + 1;
                        }
                    }
                }
                // check line
                for(i = 0; i < 4; i++){
                    if(py+i < Table_ht-1){
                        bool bLine = true;
                        for(j = 1; j < Table_wh-1; j++){
                            if(pField[(py+i)*Table_wh + j] == 0) bLine = false;
                        }
                        if(bLine){
                            for(j = 1; j < Table_wh-1; j++){
                                pField[(py+i)*Table_wh + j] = 8;
                            }

                            vLine.push_back(py+i);
                        }
                    }
                }
                // next piece
                CurrentPiece = rand() % 7;
                r = 0;
                px = Table_wh/2-1;
                if(CurrentPiece == 0) py = 1;
                else if(CurrentPiece == 1 || CurrentPiece == 3 || CurrentPiece == 4) py = 0;
                else py = -1;
                // game over
                GAME = noCollide(px, py+1, r, CurrentPiece);
                // accelerate
                if(nSpeed > 100) nSpeed -= 2;
            }
            forceDown = false;
        }

        /// OUTPUT

        if(!vLine.empty()) nScore += (1 << vLine.size()) * (1 << vLine.size()) * 10;
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y-2)+SCREEN_WIDTH/2-3], 7, "TETRIS");
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y+Table_ht/6) + Table_x + Table_wh + 2], 8, "Score: ");
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y+Table_ht/6+2) + Table_x + Table_wh +1], 9, "%8d", nScore);
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y+Table_ht/6) +2], 4, "KEY");
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y+Table_ht/6+2) +3], 10, "Z: rotate");
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y+Table_ht/6+3) +3], 9, "Left key");
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y+Table_ht/6+4) +3], 10, "Right key");
        sprintf_s(&screen[SCREEN_WIDTH*(Table_y+Table_ht/6+5) +3], 9, "Down key");

        /// Draw Field

        for(i = 0; i < Table_ht; i++){
            for(j = 0; j < Table_wh; j++){
                screen[ (i+Table_y)*SCREEN_WIDTH + (j+Table_x) ] = " ABCDEFG=O"[ pField[i*Table_wh + j] ];
            }
        }
        for(i = 0; i < 4; i++){
            for(j = 0;j < 4; j++){
                if(tetromino[CurrentPiece][ Rotate(j, i, r, tetromino[CurrentPiece][0]) ] == 'X')
                    screen[(py+i+Table_y) * SCREEN_WIDTH + (px+j+Table_x)] = CurrentPiece + 65;
            }
        }


        WriteConsoleOutputCharacter(hCon, screen, SCREEN_WIDTH*SCREEN_HEIGHT, {0,0}, &dwBytesWritten);

        /// Line

        if(!vLine.empty()){
            Sleep(200);
            for(auto &v : vLine){
                for(i = v; i > 1; i--){
                    for(j = 1; j < Table_wh-1; j++){
                        pField[i*Table_wh+j] = pField[(i-1)*Table_wh+j];
                    }
                }
                for(j = 1; j < Table_wh-1; j++){
                    pField[i*Table_wh+j] = 0;
                }
            }
            vLine.clear();
        }

    }

    return 0;
}







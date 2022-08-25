#include<iostream>
#include<windows.h>
#include<time.h>

int scrW = 120, scrH = 40;

int main()
{
    clock_t base = clock();
    clock_t now = clock();
    int FPS = 0, F = 0;
//    while(1){
//        F++;
//        now = clock();
//        if(now - base > 1000){
//            base = now;
//            FPS = F;
//            F = 0;
//        }
//
//        system("cls");
//    }

    char *screen = new char[scrW*scrH];
    HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, nullptr);
    SetConsoleActiveScreenBuffer(hCon);
    DWORD bitwir = 0;
int i;
    while(1){
        F++;
        now = clock();
        if(now - base > 1000){
            base = now;
            FPS = F;
            F = 0;
        }

        screen[0] = 'F';
        screen[1] = 'P';
        screen[2] = 'S';
        screen[3] = ':';
        screen[4] = ' ';
        screen[5] = '0' + FPS/1000;
        screen[6] = '0' + FPS%1000 / 100;
        screen[7] = '0' + FPS%100 / 10;
        screen[8] = '0' + FPS%10;
        for(i = 9; i < scrW*scrH; i++) screen[i] = ' ';
         screen[scrW*scrH - 1] = '\0';
        WriteConsoleOutputCharacter(hCon, screen, scrW*scrH, {0,0}, &bitwir);
    }


    return 0;
}

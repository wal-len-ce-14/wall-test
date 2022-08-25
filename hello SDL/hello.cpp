#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

bool init();
bool loadMedia();
void close();

SDL_Window *gWindow = nullptr;
SDL_Surface *gScreenSurface = nullptr;
SDL_Surface *gHelloWorld = nullptr;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    if(!init()){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }else{
        if(!loadMedia()){
            printf("Failed to load media");
        }else{
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Delay(2000);
        }
    }
    close();

    return 0;
}

bool init(){
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("SDL could not initialize!! SDL Error: %s", SDL_GetError());
        success = false;
    }else{
        gWindow = SDL_CreateWindow("Hello", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == nullptr){
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia(){
    bool success = true;
    gHelloWorld = SDL_LoadBMP("img/hello_world.bmp");
    if(gHelloWorld == NULL){
        printf( "Unable to load image %s! SDL Error: %s\n", "img/hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void close(){
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = nullptr;
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    SDL_Quit();
}

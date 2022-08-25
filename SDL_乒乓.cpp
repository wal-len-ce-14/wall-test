#include<stdio.h>
#include<SDL.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
void close();

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

class ball{
    private:
        int mx, my, w, h;
        SDL_Rect mball;
    public:
        ball(int x, int y){
            mx = x;
            my = y;
            w = 5;
            h = 5;
        }
};

class LTexture{

    private:
        SDL_Texture* mTexture;


        int mWidth;
		int mHeight;
		int mx, my;

    public:
        SDL_Rect renderQuad;
        LTexture();
        LTexture(int wh, int ht, int x, int y);
        ~LTexture();

        void free();
        void render(int x, int y);
        int getWidth(){ return mWidth; };
		int getHeight(){ return mHeight; };
		int getcorX(){ return mx; }
		int getcorY(){ return my; }
		void move_cor(int xdir, int ydir);
};

LTexture::LTexture(){

	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
	mx = SCREEN_WIDTH / 2;
	my = SCREEN_HEIGHT / 2;
}
LTexture::LTexture(int wh, int ht, int x, int y){

	mTexture = nullptr;
	mWidth = wh;
	mHeight = ht;
	mx = x;
	my = y;
	renderQuad = { mx, my, mWidth, mHeight };
//    SDL_RenderFillRect( gRenderer, &renderQuad );
}
LTexture::~LTexture(){
    free();
}
void LTexture::free(){

	if( mTexture != nullptr )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}
void LTexture::render(int x, int y){
    printf("111\n");
    renderQuad.x = x;
    renderQuad.y = y;
//    SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );

    if(SDL_RenderFillRect( gRenderer, &renderQuad ) != 0){
        printf("%s\n", SDL_GetError());
    };
    printf("ddd\n");
    SDL_RenderPresent( gRenderer );
    SDL_Delay(1000);
}
void LTexture::move_cor(int xdir, int ydir){
    render(mx + xdir, my + ydir);
    mx = mx + xdir;
    my = my + ydir;
}

LTexture gTexture;

int main( int argc, char* args[] ){
    int f = 0, FPS = 0;


    if(!init()){
        printf("Failed to initialize!\n");
    }else{
        bool quit = false;
        LTexture racket(20, 100, 60, (SCREEN_HEIGHT/2) - 100/2);
        SDL_Event e;

        while(!quit){
                SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
                SDL_RenderClear( gRenderer );
            while( SDL_PollEvent( &e ) != 0 ){

                SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 0xFF );
                if( e.type == SDL_QUIT ){
                    quit = true;
                }

                if( e.type == SDL_KEYDOWN ){

                    switch( e.key.keysym.sym ){
                        case SDLK_w:
                            if(racket.getcorY() > 50){
                                racket.move_cor(0,-10);
                                printf("%d, %d\n", racket.getcorX(), racket.getcorY());
                            }

                            break;
                        case SDLK_s:
                            if(racket.getcorY() < SCREEN_HEIGHT-50-100){
                                racket.move_cor(0,10);
                                printf("%d, %d\n", racket.getcorX(), racket.getcorY());
                            }
                            break;
                    }
                }

            }
                //SDL_Rect fillRect = {racket.getcorX() , racket.getcorY(), racket.getWidth(), racket.getHeight() };
				SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0xFF );
				SDL_RenderFillRect( gRenderer, &racket.renderQuad );
				//SDL_RenderFillRect( gRenderer, &fillRect );

            SDL_RenderPresent( gRenderer );
        }


    }

    close();

    return 0;
}

bool init(){

    bool success = true;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ){
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}else{
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if(gWindow == NULL){
			printf( "Window could not be created! %s\n", SDL_GetError() );
			success = false;
		}else{
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL ){
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
		}
	}

	return success;
}

void close(){

    gTexture.free();
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );

    gWindow = nullptr;
	gRenderer = nullptr;

	SDL_Quit();
}





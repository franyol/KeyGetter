#include "SDL2/SDL.h"
#include <iostream>
#include "keyboard.h"

//Starts SDL and creates the window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void windowStayUp();

const int SCREEN_WIDTH = 556;
const int SCREEN_HEIGHT = 424;
const int FRAMERATE = 15;

SDL_Window* window = NULL;
SDL_Rect kbRect;
SDL_Renderer* renderer = NULL;

int main( int argc, char* args[])
{
    if (!init()) 
	std::cerr << "Failed to initialize." << std::endl;
    else {
    	loadMedia();
	kbRect.x = 0;
	kbRect.y = SCREEN_HEIGHT/2;
	kbRect.w = _kbWidth;
	kbRect.h = _kbHeight;
    }

    // Start event loop
    SDL_Event event;

    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
	    if (event.type == SDL_QUIT)
		quit = true;
	}
        
	keyboardRenderCopy(renderer, SDL_GetKeyboardState(NULL), &kbRect);
        
        SDL_RenderPresent(renderer);
	SDL_Delay(1000/FRAMERATE);
    }

    close();
    return 0;
}

bool init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
	std::cerr << "Could not initialize, SDL_Error: " << SDL_GetError() << std::endl;
	success = false;
    }
    else {
        window = SDL_CreateWindow("keyget", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, SCREEN_HEIGHT, 
			SDL_WINDOW_RESIZABLE);
	if(window == NULL) {
	    std::cerr 
		<< "Window could not be created, SDL_ERROR: " 
		<< SDL_GetError() << std::endl;
	    success = false;
	}
	else {
	    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	    if (renderer == NULL) {
	        std::cout << "Error loading renderer: " << SDL_GetError() << std::endl;
		success = false;
	    }
	}
    }

    return success;
}

bool loadMedia() {
    bool success = true;

    initKeyboard( renderer );
     
    return success;
}

void close() {
    quitKeyboard();

    SDL_DestroyWindow( window );
    window = NULL;

    SDL_DestroyRenderer( renderer );
    renderer = NULL;

    SDL_Quit();
}

void windowStayUp() {
    SDL_Event e;
    bool quit = false;

    while (quit == false ) {
    	while( SDL_PollEvent( &e ) ) {
		if( e.type == SDL_QUIT )
			quit = true;
	}
    }
}

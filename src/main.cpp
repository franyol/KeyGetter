#include <SDL2/SDL.h>
#include <iostream>
#include <keyboard.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <cmath>

//Starts SDL and creates the window
bool init();

//Loads media
bool loadMedia();
bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

//Frees media and shuts down SDL
void close();

void windowStayUp();

const int SCREEN_WIDTH = 556;
const int SCREEN_HEIGHT = 424;
const int FRAMERATE = 15;

TTF_Font* font = NULL;
SDL_Texture* textTexture = NULL;
int textWidth = 0;
int textHeight = 0;

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

    SDL_Color textColor = {0, 0, 0, 0xFF};

    std::string inputText = "Some Text";
    loadFromRenderedText( inputText.c_str(), textColor );

    SDL_StartTextInput();

    bool quit = false;
    while (!quit) {

	bool renderText = false;

        while (SDL_PollEvent(&event) != 0) {
	    if (event.type == SDL_QUIT)
		quit = true;
	    else if ( event.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 ) {
	        inputText.pop_back();
		renderText = true;
	    }
	    else if ( event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL ) {
	        SDL_SetClipboardText( inputText.c_str() );
	    } else if ( event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL ) {
	        inputText = SDL_GetClipboardText();
		renderText = true;
	    } else if ( event.type == SDL_TEXTINPUT ) {
		// If not copy or pasting
	        if( !( SDL_GetModState() & KMOD_CTRL && 
		      ( event.text.text[ 0 ] == 'c' || event.text.text[ 0 ] == 'C' ||
		        event.text.text[ 0 ] == 'v' || event.text.text[ 0 ] == 'V' ) ) ) {
		    inputText += event.text.text;
		    renderText = true;
		}
	    }

	}
        
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( renderer );

	if( renderText ) {
	    if( inputText != "" ) {
	        loadFromRenderedText( inputText.c_str(), textColor );
	    } else {
	        loadFromRenderedText( " ", textColor );
	    }
	}
	keyboardRenderCopy(renderer, SDL_GetKeyboardState(NULL), &kbRect);
        
        SDL_Rect textQuad = { SCREEN_WIDTH/10, SCREEN_HEIGHT/10, textWidth, textHeight };
	SDL_RenderCopy( renderer, textTexture, NULL, &textQuad );

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
        int imgFlags = IMG_INIT_PNG;
	if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {
	    std::cout << "SDL_image could not initialize: " << IMG_GetError() << std::endl;
	    success = false;
	}
	if ( TTF_Init() == -1 ) {
	    std::cout << "SDL_ttf could not initialize: " << TTF_GetError() << std::endl;
	    success = false; 
	}
	
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

    font = TTF_OpenFont( "assets/Raleway-Black.ttf", 18 );
    if (font == NULL) {
        std::cout << "Falied to load font: " << TTF_GetError() << std::endl;
	success = false;
    }
     
    return success;
}

bool loadFromRenderedText( std::string textureText, SDL_Color textColor ) {
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
    if (textSurface == NULL) {
        std::cout << "Unable to render text surface: " 
		<< SDL_GetError() << std::endl;
    }
    else {
       textTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
       if ( textTexture == NULL ) {
           std::cout << "Unable to create texture from rendered text: "
		   << SDL_GetError() << std::endl;
       }
       else {
           textWidth = textSurface->w;
	   textHeight = textSurface->h;
       }

       SDL_FreeSurface( textSurface );
    }

    return textTexture != NULL;
}

void close() {
    quitKeyboard();

    SDL_DestroyTexture( textTexture );
    textTexture = NULL;
    TTF_CloseFont( font );
    font = NULL;

    SDL_DestroyWindow( window );
    window = NULL;

    SDL_DestroyRenderer( renderer );
    renderer = NULL;

    TTF_Quit();
    IMG_Quit();
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

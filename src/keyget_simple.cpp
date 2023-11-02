#include "SDL2/SDL.h"
#include <iostream>

//Starts SDL and creates the window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void windowStayUp();

const int SCREEN_WIDTH = 556;
const int SCREEN_HEIGHT = 212;
const int FRAMERATE = 15;

struct key {
    const char *str;
    int x;
    int y;
    int width;
    int height;
};

const key keys[232] = {
    {"unknown",0,0,0,0}, {nullptr,0,0,0,0},{nullptr,0,0,0,0},{nullptr,0,0,0,0},
    // Abecedary from index=4 to index=29
    {"a",62,97,38,37}, {"b",235,134,38,37}, {"c",159,134,38,37}, {"d",140,97,38,37},
    {"e",133,59,38,37}, {"f",178,97,38,37}, {"g",217,97,38,37}, {"h",256,97,38,37},
    {"i",326,59,38,37}, {"j",294,97,38,37}, {"k",332,97,38,37}, {"l",370,97,38,37},
    {"m",312,134,38,37}, {"n",274,134,38,37}, {"o",364,59,38,37}, {"p",402,59,38,37},
    {"q",55,59,38,37}, {"r",172,59,38,37}, {"s",102,97,38,37}, {"t",209,59,38,37},
    {"u",285,59,38,37}, {"v",197,134,38,37}, {"w",94,59,38,37}, {"x",119,134,38,37},
    {"y",249,59,38,37}, {"z",83,134,38,37},
    // Numbers from index=30 to index=39
    {"1",37,20,38,37}, {"2",77,20,38,37}, {"3",115,20,38,37}, {"4",152,20,38,37},
    {"5",193,20,38,37}, {"6",231,20,38,37}, {"7",269,20,38,37}, {"8",309,20,38,37},
    {"9",347,20,38,37}, {"0",384,20,38,37},
    // Miscellaneous from index=40 to index=57
    {"\n",489,97,69,37}, {"esc",0,0,29,19}, {"\b \b",500,20,56,37}, {"\t",0,59,55,37},
    {" ",158,175,231,37}, {"-",423,20,38,37}, {"=",462,20,38,37}, {"[ ",442,59,38,37},
    {"]",479,59,38,37}, {"\\",519,59,38,37}, {nullptr,0,0,0,0}, {";",409,97,38,37},
    {"'",448,97,38,37}, {"`",0,20,38,37}, {",",351,134,38,37}, {".",389,134,38,37},
    {"/",428,134,38,37}, {"caps",0,97,63,37},
    // f-keys from index=58 to index=69
    {"f1",30,0,29,19}, {"f2",59,0,29,19}, {"f3",90,0,29,19}, {"f4",121,0,29,19},
    {"f5",151,0,29,19}, {"f6",182,0,29,19}, {"f7",212,0,29,19}, {"f8",243,0,29,19},
    {"f9",273,0,29,19}, {"f10",303,0,29,19}, {"f11",334,0,29,19}, {"f12",364,0,29,19},
    // index=70 to index=78
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},
    // Arrows from index=79 to index=82
    {"right",526,193,28,18}, {"left",468,193,28,18}, {"down",496,193,28,18},
    {"up",497,176,28,18},
    // index=83 to index=223
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0}, // index=100
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0}, //120
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0}, //160
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0}, //200
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},
    {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  {nullptr,0,0,0,0},  
    // Controls from index=224 to index=231
    {"Lctrl",37,175,43,35}, {"Lshift",0,134,81,37}, {"Lalt",119,175,38,37},
    {"Lgui",82,175,38,37}, {"Rctrl",429,175,38,37}, {"Rshift",466,134,90,37},
    {"Ralt",389,175,38,37}, {"Rgui",82,175,38,37}
};

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* keyboard = NULL;
SDL_Surface* keyboard_alt = NULL;

SDL_Rect keyRect;

int main( int argc, char* args[])
{
    if (!init()) 
	std::cerr << "Failed to initialize." << std::endl;
    else {
    	loadMedia();
    }

    // Start event loop
    SDL_Event e;

    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
	    if (e.type == SDL_QUIT)
		quit = true;
	}
	
	SDL_BlitSurface( keyboard, NULL, screenSurface, NULL );
        
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	int press = false;
	for (int i=0; i<232; i++) {
	    if (currentKeyStates[i]) {
		std::cout << keys[i].str << std::flush;
	    	press = true;

		keyRect.x = keys[i].x;
		keyRect.y = keys[i].y;
		keyRect.w = keys[i].width;
		keyRect.h = keys[i].height;

	        SDL_BlitSurface( keyboard_alt, &keyRect, screenSurface, &keyRect );
	    }
	}

        SDL_UpdateWindowSurface( window );
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
	    screenSurface = SDL_GetWindowSurface( window );
	}
    }

    return success;
}

bool loadMedia() {
    bool success = true;

    keyboard = SDL_LoadBMP( "assets/laptops-keyboard.bmp" );
    if(keyboard == NULL) {
	std::cerr << "Unable to load image, SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    keyboard_alt = SDL_LoadBMP( "assets/laptops-keyboard-alt.bmp" );
    if(keyboard_alt == NULL) {
	std::cerr << "Unable to load image, SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }

    return success;
}

void close() {
    SDL_FreeSurface( keyboard );
    keyboard = NULL;
    SDL_FreeSurface( keyboard_alt );
    keyboard_alt = NULL;

    SDL_DestroyWindow( window );
    window = NULL;

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

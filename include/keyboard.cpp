#include "keyboard.h"
#include "SDL2/SDL.h"
#include <iostream>

const char* _K_BMP_PATH = "assets/laptops-keyboard.bmp";
const char* _K_ALT_BMP_PATH = "assets/laptops-keyboard-alt.bmp";

const _KEY _KEYS[232] = {
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

SDL_Texture* _kTexture;
SDL_Texture* _kAltTexture;

int _kbWidth = 0;
int _kbHeight = 0;

bool initKeyboard( SDL_Renderer* renderer ) {
    bool success = true;

    SDL_Surface* tempKeySurface = NULL;

    tempKeySurface = SDL_LoadBMP(_K_BMP_PATH);
    if (tempKeySurface != NULL)
        _kTexture = SDL_CreateTextureFromSurface( renderer, tempKeySurface );
    else success = false;
    
    tempKeySurface = SDL_LoadBMP(_K_ALT_BMP_PATH);
    if (tempKeySurface != NULL)
        _kAltTexture = SDL_CreateTextureFromSurface( renderer, tempKeySurface );
    else success = false;

    if ( _kTexture == NULL || _kAltTexture == NULL ) {
        std::cout << "keyboard.h: Error loading textures" << SDL_GetError() << std::endl;
	success = false;
    }

    SDL_FreeSurface( tempKeySurface );

    if (SDL_QueryTexture( _kTexture, NULL, NULL, &_kbWidth, &_kbHeight ) > 0) {
        std::cout << "Error querying keyboard texture, Error: " 
		<< SDL_GetError() << std::endl;
	success = false;
    }

    return success;
}

void quitKeyboard()  {
    SDL_DestroyTexture( _kTexture );
    SDL_DestroyTexture( _kAltTexture );

    _kTexture = NULL;
    _kAltTexture = NULL;
}

bool keyboardRenderCopy(SDL_Renderer* renderer,
		        const Uint8* currentKeyStates,
			const SDL_Rect* dstrect) {
    bool press = false;
    SDL_Rect keyRect;

    SDL_Texture* auxtexture = SDL_CreateTexture(renderer,
			    SDL_PIXELFORMAT_RGBA8888,
			    SDL_TEXTUREACCESS_TARGET,
			    _kbWidth,
			    _kbHeight);
    SDL_SetTextureBlendMode(auxtexture, SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(renderer, auxtexture);
    SDL_RenderCopy(renderer, _kTexture, NULL, NULL);

    for (int i=0; i<232; i++) {
        if (currentKeyStates[i]) {
	    press = true;

	    keyRect.x = _KEYS[i].x;
	    keyRect.y = _KEYS[i].y;
	    keyRect.w = _KEYS[i].width;
	    keyRect.h = _KEYS[i].height;

	    SDL_RenderCopy(renderer, _kAltTexture, &keyRect, &keyRect);
	}
    }

    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, auxtexture, NULL, dstrect);
    SDL_DestroyTexture(auxtexture);

    return press;
}

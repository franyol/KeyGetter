#include <SDL2/SDL.h>

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_
   
    extern int _kbWidth;
    extern int _kbHeight;

    extern SDL_Texture* _kTexture;
    extern SDL_Texture* _kAltTexture;

    struct _KEY {
        const char *str;
        int x;
        int y;
        int width;
        int height;
    };

    bool initKeyboard( SDL_Renderer* renderer );
    /*
     * @brief: Load keyboard bmp images and create it's SDL_Texture's
     *
     * @return: true if media load succeeded, false otherwise.
     * */

    void quitKeyboard();
    /*
     * @brief: free keyboard SDL_Textures 
     * */

    bool keyboardRenderCopy(SDL_Renderer* renderer,
		            const Uint8* currentKeyStates,
			    const SDL_Rect* dstrect);
    /*
     * @brief: copy keyboard with key-presses to renderer
     *
     * @return: true if a key was pressed
     * */
#endif

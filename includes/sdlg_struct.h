#ifndef SDLG_INCLUDE_H
#define SDLG_INCLUDE_H

#define _XOPEN_SOURCE 500

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t width;
    size_t height;
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDLGames_window;

typedef struct
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int opacity;
} SDLGames_Color;

// Size window
#define RECT(X, Y, W, H) X, Y, W, H

// Primary colors consts
#define GREEN (SDLGames_Color){ 0, 255, 0, 255 }
#define RED (SDLGames_Color){ 255, 0, 0, 255 }
#define BLUE (SDLGames_Color){ 0, 0, 255, 255 }
#define BLACK (SDLGames_Color){ 0, 0, 0, 255 }
#define WHITE (SDLGames_Color){ 255, 255, 255, 255 }

#endif

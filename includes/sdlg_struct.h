#ifndef SDLG_INCLUDE_H
#define SDLG_INCLUDE_H

#define _XOPEN_SOURCE 500

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t size;
    SDL_Renderer *curr;
    SDL_Renderer **renderers;
} SDLGames_Renderers;

typedef struct
{
    size_t width;
    size_t height;
    SDL_Window *window;

    SDLGames_Renderers *renderer;
} SDLGames_Window;

typedef struct
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int opacity;
} SDLGames_Color;

typedef union
{
    SDLGames_Color color;
    SDL_Surface *image;
} SDLGames_DisplayData;

enum SDLGames_TypeDisplay
{
    SOLID_PLAIN = 1,
    SOLID_EMPTY = 2,
    IMAGE = 3,
}

typedef struct
{
    enum SDLGames_TypeDisplay type;
    SDLGames_DisplayData data;
} SDLGames_KindDisplay;

// All arguments for a rectangle
#define RECT(X, Y, W, H) X, Y, W, H

// Primary colors
#define GREEN 0, 255, 0, 255
#define RED 255, 0, 0, 255
#define BLUE 0, 0, 255, 255
#define BLACK 0, 0, 0, 255
#define WHITE 255, 255, 255, 255

#define SDLG_COLOR(r, g, b, a)                                                 \
    (SDLGames_Color)                                                           \
    {                                                                          \
        r, g, b, a                                                             \
    }
#define UW_COLOR(color) color.red, color.green, color.blue, color.opacity

#endif

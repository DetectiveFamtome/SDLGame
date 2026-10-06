#ifndef SDLG_INCLUDE_H
#define SDLG_INCLUDE_H

#define _XOPEN_SOURCE 500

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SDLGames_InitArgs
{
    char *window_name;
    size_t w;
    size_t h;
    Uint32 window_option;

    size_t nb_renderers;

} SDLGames_InitArgs;

typedef struct SDLGames_Renderers
{
    size_t max;
    size_t curr_max;

    SDL_Renderer *curr;
    SDL_Renderer **renderers;

} SDLGames_Renderers;

typedef struct SDLGames_Window
{
    size_t width;
    size_t height;

    SDL_Window *window;

    SDLGames_Renderers *renderers;

} SDLGames_Window;

typedef struct SDLGames_Color
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int opacity;

} SDLGames_Color;

typedef union SDLGames_DisplayData
{
    SDLGames_Color color;
    SDL_Surface *image;

} SDLGames_DisplayData;

enum SDLGames_TypeDisplay
{
    SOLID_PLAIN = 1,
    SOLID_EMPTY = 2,
    IMAGE = 3,
};

typedef struct SDLGames_KindDisplay
{
    enum SDLGames_TypeDisplay type;
    SDLGames_DisplayData data;
} SDLGames_KindDisplay;

// All arguments for a rectangle
#define RECT(X, Y, W, H)                                                       \
    (SDL_FRect)                                                                \
    {                                                                          \
        X, Y, W, H                                                             \
    }

// Primary colors
#define GREEN(opacity) 0, 255, 0, opacity
#define RED(opacity) 255, 0, 0, opacity
#define BLUE(opacity) 0, 0, 255, opacity
#define BLACK(opacity) 0, 0, 0, opacity
#define WHITE(opacity) 255, 255, 255, opacity

#define SDLG_COLOR(r, g, b, a)                                                 \
    (SDLGames_Color)                                                           \
    {                                                                          \
        r, g, b, a                                                             \
    }

#define UW_COLOR(color) color.red, color.green, color.blue, color.opacity

#endif

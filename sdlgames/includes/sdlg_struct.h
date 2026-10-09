#ifndef SDLG_INCLUDE_H
#define SDLG_INCLUDE_H

#define _XOPEN_SOURCE 500

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

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
    (SDL_Color)                                                                \
    {                                                                          \
        r, g, b, a                                                             \
    }

#define UW_COLOR(color) color.r, color.g, color.b, color.a

// ##### Init and main window ######

typedef struct SDLGames_InitArgs
{
    char *window_name;
    size_t w;
    size_t h;
    Uint32 window_option;

    size_t nb_renderers;

} SDLGames_InitArgs;

typedef struct SDLGames_Window
{
    size_t width;
    size_t height;
    SDL_Window *window;

    SDL_Renderer *renderer;

    SDL_Texture *texture;

} SDLGames_Window;

// ##### "Displayable" Object #####

enum SDLGames_TypeObject
{
    DISPLAY_RENDERER,
    DISPLAY_TEXTURE,
    DISPLAY_SOLID,
};

typedef union SDLGames_ObjectData
{
    SDL_Surface *surface;
    SDL_Texture *teture;
    SDL_Color *color;
} SDLGames_ObjectData;

typedef struct SDLGames_Object
{
    enum SDLGames_TypeObject type;
    SDL_FRect position;
    SDLGames_ObjectData *objet;
} SDLGames_Object;

#endif

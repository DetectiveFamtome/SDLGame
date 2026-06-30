#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    SDL_Window* window;
    SDL_Renderer* renderer;
} SDLGames_window;

typedef struct
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int opacity;
} SDLGames_color;

// Primary colors consts
#define GREEN (SDLGames_color){0, 255, 0, 255}
#define RED (SDLGames_color){255, 0, 0, 255}
#define BLUE (SDLGames_color){0, 0, 255, 255}
#define BLACK (SDLGames_color){0, 0, 0, 255}
#define WHITE (SDLGames_color){255, 255, 255, 255}
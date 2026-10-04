#include "solid.h"

void SDLGames_DrawSolid(SDLGames_window *sdlg_window, SDL_FRect rect,
                        SDLGames_color color)
{
    /*
        inputs: SDLGames_window*: Window to draw
                SDL_rect*: Informations where to draw
                SDLGames_color: The color of the shape

        description: Shortcut to draw a shape on a window
    */

    SDL_SetRenderDrawColor(sdlg_window->renderer, color.red, color.green,
                           color.blue, color.opacity);
    SDL_RenderFillRect(sdlg_window->renderer, &rect);
}

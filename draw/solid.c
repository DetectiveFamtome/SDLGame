#include "solid.h"

void SDLGames_DrawSolidRect(SDLGames_Window *sdlg_window, SDL_FRect rect,
                            SDL_Color color)
{
    /*
        inputs: SDLGames_window*: Window to draw
                SDL_rect*: Informations where to draw
                SDLGames_color: The color of the shape

        description: Shortcut to draw a shape on a window
    */

    SDL_SetRenderDrawColor(sdlg_window->renderers->curr, UW_COLOR(color);
    SDL_RenderFillRect(sdlg_window->renderers->curr, &rect);
}

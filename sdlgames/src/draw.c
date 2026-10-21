#include "draw.h"

void SDLGames_DrawObject(SDLGames_Window* window, SDLGames_DisplayObject* object)
{
	
	if (object->type == DISPLAY_TEXTURE)
	{	
		if (object->texture == NULL)
		{
			// TODO Warning/Err dans ce cas la
			return;
		}
		SDL_RendererTexture(window->renderer, object->texture, NULL, NULL);	
	}
	
}

void SDLGames_DrawSolidRect(SDLGames_Window *sdlg_window, SDL_FRect rect,
                            SDL_Color color)
{
    /*
        inputs: SDLGames_window*: Window to draw
                SDL_rect*: Informations where to draw
                SDLGames_color: The color of the shape

        description: Shortcut to draw a shape on a window
    */

    SDL_SetRenderDrawColor(sdlg_window->renderer, UW_COLOR(color));
    SDL_RenderFillRect(sdlg_window->renderer, &rect);
}

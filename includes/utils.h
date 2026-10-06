#ifndef SDLG_UTILS_H
#define SDLG_UTILS_H

#include "sdlg_struct.h"

char SDLGames_FindEvent(Uint32 search_event);
void SDLGames_Update(SDLGames_Window *window);
SDLGames_Window *SDLGames_Init(char *window_name, unsigned int w,
                               unsigned int h, Uint32 option_window);

void SDLGames_Quit(SDLGames_Window *wind);
void SDLGames_ClearBack(SDLGames_Window *wind, SDLGames_Color color);
#endif

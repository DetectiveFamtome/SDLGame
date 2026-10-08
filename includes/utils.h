#ifndef SDLG_UTILS_H
#define SDLG_UTILS_H

#include "sdlg_struct.h"

char SDLGames_FindEvent(Uint32 search_event);
void SDLGames_Update(SDLGames_Window *window);
SDLGames_Window *SDLGames_Init(SDLGames_InitArgs args);

void SDLGames_Quit(SDLGames_Window *wind);
#endif

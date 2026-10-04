#ifndef SDLG_UTILS
#define SDLG_UTILS

#include "sdlg_struct.h"

char SDLGames_FindEvent(Uint32 search_event);
void SDLGames_update(SDLGames_window *window);
SDLGames_window *SDLGames_init(char *window_name, unsigned int w,
                               unsigned int h, Uint32 option_window);

void SDLGames_quit(SDLGames_window *wind);
#endif

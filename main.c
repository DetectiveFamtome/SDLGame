#include "sdlg.h"

int main()
{
    SDLGames_window *wind =
        SDLGames_init("Manifique", (SDL_Rect){ 200, 200, 200, 200 }, 0, 0);

    char running = 1;

    while (running)
    {
        running = !SDLGames_FindEvent(SDL_EVENT_QUIT);

        SDLGames_DrawSolid(wind, (SDL_Rect){ 10, 10, 10, 10 }, GREEN);

        SDLGames_update(wind);
    }

    SDLGames_quit(wind);

    return 0;
}

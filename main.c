#include "sdlg.h"

int main()
{
    SDLGames_Window *wind = SDLGames_Init("Manifique", 1420, 1000, 0);

    char running = 1;

    size_t x = 0;
    size_t y = 0;
    int x_s = 1;
    int y_s = x_s;

    while (running)
    {
        running = !SDLGames_FindEvent(SDL_EVENT_QUIT);

        SDLGames_ClearBack(wind, BLACK);

        x += x_s;
        y += y_s;

        if (x == 0 || x + 20 >= wind->width)
        {
            x_s = -x_s;
        }
        if (y == 0 || y + 20 >= wind->height)
        {
            y_s = -y_s;
        }

        SDLGames_DrawSolidRect(wind, (SDL_FRect){ RECT(x, y, 20, 20) }, GREEN);

        SDLGames_Update(wind);
        SDL_Delay(5);
    }

    SDLGames_Quit(wind);

    return 0;
}

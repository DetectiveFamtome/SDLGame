#include "sdlg.h"

struct Bob
{
    size_t x;
    size_t y;

    size_t w;
    size_t h;

    int vel_x;
    int vel_y;
};

void update_bob(struct Bob *bob, SDLGames_Window *wind)
{
    bob->x += bob->vel_x;
    bob->y += bob->vel_y;

    if (bob->x == 0 || bob->x + 20 >= wind->width)
    {
        bob->vel_x = -bob->vel_x;
    }
    if (bob->y == 0 || bob->y + 20 >= wind->height)
    {
        bob->vel_y = -bob->vel_y;
    }

    SDLGames_DrawSolidRect(wind, RECT(bob->x, bob->y, 20, 20),
                           SDLG_COLOR(0, 255, 0, 255));
}

int main(void)
{
    SDLGames_InitArgs arg = { "Hibou", 1400, 1000, 0, 1 };
    SDLGames_Window *wind = SDLGames_Init(arg);

    char running = 1;

    struct Bob bobs[10] = {
        { 20, 20, 20, 20, -1, 9 }, { 20, 20, 20, 20, -2, 9 },
        { 20, 20, 20, 20, -3, 8 }, { 20, 20, 20, 20, -4, 7 },
        { 20, 20, 20, 20, -5, 6 }, { 20, 20, 20, 20, -6, 5 },
        { 20, 20, 20, 20, -6, 4 }, { 20, 20, 20, 20, -7, 3 },
        { 20, 20, 20, 20, -8, 2 }, { 20, 20, 20, 20, -9, 1 }
    };

    while (running)
    {
        running = !SDLGames_FindEvent(SDL_EVENT_QUIT);

        for (int i = 0; i < 10; i++)
        {
            update_bob(bobs + i, wind);
        }

        SDLGames_Update(wind);
        SDL_Delay(5);
    }

    SDLGames_Quit(wind);

    return 0;
}

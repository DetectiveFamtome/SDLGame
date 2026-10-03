#include "main.h"

#include <SDL2/SDL_render.h>
#include <unistd.h>

SDLGames_window *SDLGames_init(char *window_name, SDL_Rect position,
                               Uint32 option_window, Uint32 option_renderer)
{
    /*
        inputs: char*: window's name
                uint: x position of the window
                uint: y position of the window
                uint: width of the window
                uint: height of the window
                Uint32: SDL's window option (see SDL windows options)

        output: SDL_Window*: Pointer to the new window or null (if the init
       fail)

        description: Shortcut for initilize SDL window.
    */

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDLGames: Something is wrong with initialisation of SDL\n");
        return NULL;
    }

    SDLGames_window *result = malloc(sizeof(SDLGames_window));
    if (result == NULL)
    {
        printf("SDL_games: Fail to creat SDLGames_window\n");
        return 0;
    }

    result->window = SDL_CreateWindow(window_name, position.x, position.y,
                                      position.w, position.h, option_window);
    result->renderer = SDL_CreateRenderer(result->window, -1, option_renderer);

    if (result == NULL || result->window == NULL || result->renderer == NULL)
    {
        printf("SDL_games: Fail to creat window or/and renderer\n");
        SDL_Quit();
    }

    return result;
}

inline char SDLGames_FindEvent(Uint32 search_event)
{
    SDL_PumpEvents();
    return SDL_PeepEvents(NULL, 0, SDL_PEEKEVENT, search_event, search_event)
        > 0;
}

inline void SDLGames_update(SDLGames_window *window, int sleep_time)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            SDL_PushEvent(&event);
            break;
        }
    }
    SDL_RenderPresent(window->renderer);
    sleep(sleep_time);
}

void SDLGames_quit(SDLGames_window *wind)
{
    /*
        input: SDLGames_window*: the target window

        description: End and free for terminate the programme
    */

    SDL_DestroyWindow(wind->window);
    SDL_DestroyRenderer(wind->renderer);

    free(wind);
    SDL_Quit();
}

int main()
{
    SDLGames_window *wind =
        SDLGames_init("Manifique", (SDL_Rect){ 200, 200, 200, 200 }, 0, 0);

    char running = 1;

    while (running)
    {
        running = SDLGames_FindEvent(SDL_QUIT);

        SDLGames_DrawSolid(wind, (SDL_Rect){ 10, 10, 10, 10 }, GREEN);

        SDLGames_update(wind, 60);
    }

    SDLGames_quit(wind);

    return 0;
}

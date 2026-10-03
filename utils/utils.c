#include "utils.h"

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

void SDLGames_update(SDLGames_window *window)
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

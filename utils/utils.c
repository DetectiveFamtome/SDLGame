#include "utils.h"

SDLGames_window *SDLGames_init(char *window_name, unsigned int w,
                               unsigned int h, Uint32 option_window)
{
    /*
        inputs: char*: window's name
                uint: width of the window
                uint: height of the window
                Uint32: SDL's window option (see SDL windows options)

        output: SDL_Window*: Pointer to the new window or null (if the init
       fail)

        description: Shortcut for initilize SDL window.
    */

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDLGames: Something is wrong with initialisation of SDL\n");
        return NULL;
    }

    SDLGames_window *result = malloc(sizeof(SDLGames_window));
    if (result == NULL)
    {
        printf("SDL_games: Fail to creat SDLGames_window\n");
        SDL_Quit();
        return NULL;
    }

    SDL_Window *wind = SDL_CreateWindow(window_name, w, h, option_window);

    if (wind == NULL)
    {
        printf("SDL_games: Fail to creat window\n");
        SDL_Quit();
        return NULL;
    }

    SDL_Renderer *r = SDL_CreateRenderer(wind, NULL);

    if (r == NULL)
    {
        printf("SDL_games: Fail to creat renderer\n");

        SDL_DestroyWindow(wind);
        SDL_Quit();
        return NULL;
    }

    result->window = wind;
    result->renderer = r;
    result->width = w;
    result->height = h;

    return result;
}

inline char SDLGames_FindEvent(Uint32 search_event)
{
    SDL_PumpEvents();
    return SDL_PeepEvents(NULL, 0, SDL_PEEKEVENT, search_event, search_event)
        > 0;
}

inline void SDLGames_ClearBack(SDLGames_window *wind, SDLGames_Color color)
{
    SDL_SetRenderDrawColor(wind->renderer, color.red, color.green, color.blue,
                           color.opacity);
    SDL_RenderClear(wind->renderer);
}

void SDLGames_update(SDLGames_window *window)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
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

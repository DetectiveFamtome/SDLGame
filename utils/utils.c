#include "utils.h"

SDLGames_Window *SDLGames_Init(SDLGames_InitArgs args)
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

    SDLGames_Window *res = malloc(sizeof(SDLGames_Window));
    if (!res)
    {
        SDL_Quit();
        return NULL;
    }

    SDLGames_Renderers *rend = malloc(sizeof(SDLGames_Renderers));
    if (!rend)
    {
        SDL_Quit();
        free(res);
        return NULL;
    }

    SDL_Window *wind =
        SDL_CreateWindow(args.window_name, args.w, args.h, args.window_option);
    if (!wind)
    {
        SDL_Quit();
        free(res);
        free(rend);
        return NULL;
    }

    SDL_Renderer *rend = SDL_CreateRenderer(wind, NULL);
    if (!f_rend)
    {
        SDL_Quit();
        free(res);
        SDL_DestroyWindow(wind);
        return NULL;
    }

    // PIXEL_FORMAT a changer ???
    SDL_Texture *text = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA32,
                                          SDL_TEXTUREACCESS_TARGET);

    res->width = args.w;
    res->height = args.h;
    res->window = wind;
    res->renderer = rend;

    return res;
}

inline char SDLGames_FindEvent(Uint32 search_event)
{
    SDL_PumpEvents();
    return SDL_PeepEvents(NULL, 0, SDL_PEEKEVENT, search_event, search_event)
        > 0;
}

inline void SDLGames_ClearBack(SDLGames_Window *wind, SDLGames_Color color)
{
    SDL_SetRenderDrawColor(wind->renderers->curr, color.red, color.green,
                           color.blue, color.opacity);
    SDL_RenderClear(wind->renderers->curr);
}

void SDLGames_Update(SDLGames_Window *window)
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

    SDL_RenderPresent(window->renderers->curr);
}

void SDLGames_Quit(SDLGames_Window *wind)
{
    /*
        input: SDLGames_window*: the target window

        description: End and free for terminate the programme
    */

    for (size_t i = 0; i <= wind->renderers->curr_max; i++)
    {
        SDL_DestroyRenderer(wind->renderers->renderers[i]);
    }

    SDL_DestroyWindow(wind->window);

    free(wind->renderers->renderers);
    free(wind->renderers);
    free(wind);
    SDL_Quit();
}

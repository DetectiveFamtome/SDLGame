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

    SDL_Window *wind =
        SDL_CreateWindow(args.window_name, args.w, args.h, args.window_option);
    if (!wind)
    {
        SDL_Quit();
        free(res);
        return NULL;
    }

    SDL_Renderer *rend = SDL_CreateRenderer(wind, NULL);
    if (!rend)
    {
        SDL_Quit();
        free(res);
        SDL_DestroyWindow(wind);
        return NULL;
    }

    // PIXEL_FORMAT a changer ???
    SDL_Texture *text = SDL_CreateTexture(
        rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, args.w, args.h);

    res->width = args.w;
    res->height = args.h;
    res->window = wind;
    res->renderer = rend;
    res->texture = text;

    SDL_SetRenderTarget(rend, text);

    return res;
}

inline char SDLGames_FindEvent(Uint32 search_event)
{
    SDL_PumpEvents();
    return SDL_PeepEvents(NULL, 0, SDL_PEEKEVENT, search_event, search_event)
        > 0;
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
    SDL_SetRenderTarget(window->renderer, NULL);
    SDL_RenderTexture(window->renderer, window->texture, NULL, NULL);
    SDL_RenderPresent(window->renderer);
    SDL_SetRenderTarget(window->renderer, window->texture);
    SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);
    SDL_RenderClear(window->renderer);
}

void SDLGames_Quit(SDLGames_Window *wind)
{
    /*
        input: SDLGames_window*: the target window

        description: End and free for terminate the programme
    */

    SDL_DestroyWindow(wind->window);
    SDL_DestroyTexture(wind->texture);
    SDL_DestroyRenderer(wind->renderer);

    free(wind);
    SDL_Quit();
}

#include "SDL/DisplaySDL.hpp"

void updateStartMenu(SDL_Window *window, SDL_Renderer *renderer, General &general, SDL_Event &event, bool &quit, bool &keyHeld)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        {
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (!keyHeld)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_s:
                    general.openSettings();
                    break;
                }
            }
            keyHeld = true;
        }
        else if (event.type == SDL_KEYUP)
        {
            keyHeld = false;
        }
    }
}

void drawStartMenu(SDL_Renderer *renderer, TTF_Font *font)
{
    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, "Hello World!", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void updateSettings(SDL_Window *window, SDL_Renderer *renderer, General &general, SDL_Event &event, bool &quit, bool &keyHeld)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        {
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (!keyHeld)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_s:
                    general.openStartMenu();
                    break;
                }
            }
            keyHeld = true;
        }
        else if (event.type == SDL_KEYUP)
        {
            keyHeld = false;
        }
    }
}

void drawSettings(SDL_Renderer *renderer, TTF_Font *font)
{
    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, "Settings", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void loop(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_Event event;
    General general;
    TTF_Font *font = TTF_OpenFont("assets/font/Minecraft.ttf", 24);
    bool quit = false;
    bool keyHeld = false;
    while (!quit)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        switch (general.getGameState())
        {
        case STATE_START_MENU:
            updateStartMenu(window, renderer, general, event, quit, keyHeld);
            drawStartMenu(renderer, font);
            break;
        case STATE_SETTINGS:
            updateSettings(window, renderer, general, event, quit, keyHeld);
            drawSettings(renderer, font);
            break;
        }
        SDL_RenderPresent(renderer);
    }
}

void Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    if (TTF_Init() != 0)
    {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return;
    }

    loop(window, renderer);
    SDL_Quit();
}
#include "SDL/DisplaySDL.hpp"

void keyboard(bool KEYS[2][322], SDL_Event event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        if (KEYS[KEYS_PRESSED][event.key.keysym.sym])
            KEYS[KEYS_REPEAT][event.key.keysym.sym] = true;
        KEYS[KEYS_PRESSED][event.key.keysym.sym] = true;
        break;
    case SDL_KEYUP:
        KEYS[KEYS_PRESSED][event.key.keysym.sym] = false;
        KEYS[KEYS_REPEAT][event.key.keysym.sym] = false;
        break;
    default:
        break;
    }
}

Vector2f percentToPixels(Vector2f percent, Vector2f windowSize)
{
    return Vector2f((percent.x * windowSize.x) / 100.0f, (percent.y * windowSize.y / 100.0f));
}

Vector2f pixelsToPercent(Vector2f pixels, Vector2f windowSize)
{
    return Vector2f((pixels.x * 100.0f) / windowSize.x, (pixels.y * 100.0f) / windowSize.y);
}

void drawWriting(SDL_Renderer *renderer, TTF_Font *font, std::string text, Vector2f position, SDL_Color color)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect;
    rect.x = position.x - surface->w / 2;
    rect.y = position.y - surface->h / 2;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void drawButton(SDL_Renderer *renderer, Button *button, Vector2f mousePosition, Vector2f windowSize, TTF_Font *font)
{
    SDL_Rect rect;
    Vector2f position = percentToPixels(button->getPosition(), windowSize);
    Vector2f size = percentToPixels(button->getSize(), windowSize);
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.x;
    rect.h = size.y;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    if (button->isMouseOver(pixelsToPercent(mousePosition, windowSize)))
    {
        SDL_RenderFillRect(renderer, &rect);
        drawWriting(renderer, font, button->getText(), Vector2f(position.x + size.x / 2, position.y + size.y / 2), {0, 0, 0});
    }
    else
    {
        SDL_RenderDrawRect(renderer, &rect);
        drawWriting(renderer, font, button->getText(), Vector2f(position.x + size.x / 2, position.y + size.y / 2), {255, 255, 255});
    }
}

void updateStartMenu(SDL_Window *window, SDL_Renderer *renderer, General &general, SDL_Event &event, bool &keyHeld, Vector2f mousePosition, const Uint32 &mouseState, Vector2f windowSize, bool KEYS[2][322])
{
    if (KEYS[KEYS_PRESSED][SDLK_ESCAPE] && !KEYS[KEYS_REPEAT][SDLK_ESCAPE])
    {
        general.setQuit(true);
        KEYS[KEYS_REPEAT][SDLK_ESCAPE] = true;
    }
    if (mouseState == SDL_BUTTON_LEFT)
    {
        if (general.getStartMenu()->getStartButton()->isMouseOver(pixelsToPercent(mousePosition, windowSize)))
        {
            general.setGameState(STATE_GAME);
        }
        else if (general.getStartMenu()->getSettingsButton()->isMouseOver(pixelsToPercent(mousePosition, windowSize)))
        {
            general.setGameState(STATE_SETTINGS);
        }
        else if (general.getStartMenu()->getQuitButton()->isMouseOver(pixelsToPercent(mousePosition, windowSize)))
        {
            general.setQuit(true);
        }
    }
}

void drawStartMenu(SDL_Renderer *renderer, TTF_Font *font, StartMenu *StartMenu, Vector2f windowSize, Vector2f mousePosition)
{
    drawButton(renderer, StartMenu->getStartButton(), mousePosition, windowSize, font);
    drawButton(renderer, StartMenu->getSettingsButton(), mousePosition, windowSize, font);
    drawButton(renderer, StartMenu->getQuitButton(), mousePosition, windowSize, font);
}

void updateSettings(SDL_Window *window, SDL_Renderer *renderer, General &general, SDL_Event &event, bool &keyHeld, bool KEYS[2][322])
{
    if (KEYS[KEYS_PRESSED][SDLK_ESCAPE] && !KEYS[KEYS_REPEAT][SDLK_ESCAPE])
    {
        general.setGameState(STATE_START_MENU);
        KEYS[KEYS_REPEAT][SDLK_ESCAPE] = true;
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

void selectState(General &general, SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font, SDL_Event &event, bool &keyHeld, Vector2f mousePosition, const Uint32 &mouseState, bool KEYS[2][322])
{
    switch (general.getGameState())
    {
    case STATE_START_MENU:
        updateStartMenu(window, renderer, general, event, keyHeld, mousePosition, mouseState, general.getWindowSize(), KEYS);
        drawStartMenu(renderer, font, general.getStartMenu(), general.getWindowSize(), mousePosition);
        break;
    case STATE_SETTINGS:
        updateSettings(window, renderer, general, event, keyHeld, KEYS);
        drawSettings(renderer, font);
        break;
    }
}

void loop(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_Event event;
    General general;
    TTF_Font *font = TTF_OpenFont("assets/font/Minecraft.ttf", 24);
    bool keyHeld = false;
    float deltaTime = 0.0f;
    bool KEYS[2][322] = {false};
    while (!general.getQuit())
    {
        float newTime = SDL_GetTicks();
        SDL_RenderClear(renderer);
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                general.setQuit(true);
            }
            keyboard(KEYS, event);
        }

        int mouseX, mouseY;
        Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

        selectState(general, window, renderer, font, event, keyHeld, Vector2f(mouseX, mouseY), mouseState, KEYS);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
        deltaTime = (SDL_GetTicks() - newTime) / 1000.0f;
        if (deltaTime < 1.0f / 60.0f)
        {
            SDL_Delay((1.0f / 60.0f - deltaTime) * 1000.0f);
        }
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

    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return;
    }

    loop(window, renderer);
    SDL_Quit();
}
#include <SDL.h>
#include <stdio.h>
#include "menuManager.h"
#include "WindowManager.h"
#include "TextMenu.h"
#include "ScoreManager.h"
#include <SDL_ttf.h>
#include "AffichageManager.h"

void ButtonMenu()
{
    SDL_Event event;
    int x, y;

    while (SDL_PollEvent(&event)) 
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            Uint32 buttons = SDL_GetMouseState(&x, &y);
            if (x > 100 && x < 500 && y > 380 && y < 480)
            {
                Player1Life = 3;
            }
        }
    }
}

void Buttons()
{
    ButtonQuit();
    AfficherQuit();

    ButtonPlay();
    AfficherPlay();

    SDL_RenderPresent(renderer);
    ButtonLogo();
}

SDL_Rect ButtonLogo()
{
    SDL_Rect button = { 250, 50, 700, 250 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button);

    return button;
}

SDL_Rect ButtonQuit()
{
    SDL_Rect button = {700, 380, 400, 100};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button);

    return button;
}


SDL_Rect ButtonPlay()
{
    SDL_Rect button = { 100, 380, 400, 100 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button);

    return button;
}
#include <SDL.h>
#include <stdio.h>
#include "menuManager.h"
#include "WindowManager.h"
#include "TextMenu.h"
#include "ScoreManager.h"
#include <SDL_ttf.h>
#include "AffichageManager.h"
#include "Movement.h"
#include "GameManager.h"
#include "Collision.h"


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
                niveauActuel = 1;
                compteurFrame = 0;
                nbTirs = 0;
                scorePlayer1 = 0;
                isInMenu = 0;
                Player1Life = 3;
            }

            if (x > 700 && x < 1100 && y > 380 && y < 480)
            {
                Quit = 1;
            }
            if (x > 1020 && x < 1145 && y > 35 && y < 75)
            {
                isInMenu = 0;
                // Afficher les options
            }
        }
    }
}

void Buttons()
{
    fond();

    ButtonQuit();
    AfficherQuit();

    ButtonPlay();
    AfficherPlay();

    ButtonLogo();

    ButtonOption();
    AfficherOption();
    

    SDL_RenderPresent(renderer);
    
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
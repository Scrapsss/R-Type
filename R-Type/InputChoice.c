#include <SDL.h>
#include <stdio.h>
#include "menuManager.h"
#include "WindowManager.h"
#include "TextMenu.h"
#include "ScoreManager.h"
#include <SDL_ttf.h>
#include "AffichageManager.h"
#include "Movement.h"
#include "GameOver.h"
#include "menuManager.h"
#include "GameManager.h"
#include "OptionsManager.h"
#include "InputChoice.h"

SDL_Rect InputGauche()
{
    SDL_Rect button1 = { 300, 400, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button1);

    return button1;
}

SDL_Rect InputDroite()
{
    SDL_Rect button1 = { 470, 400, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button1);

    return button1;
}
SDL_Rect InputHaut()
{
    SDL_Rect button2 = { 640, 400, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button2);

    return button2;
}
SDL_Rect InputBas()
{
    SDL_Rect button3 = { 810, 400, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button3);

    return button3;
}

SDL_Rect InputTir()
{
    SDL_Rect button3 = { 980, 400, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button3);

    return button3;
}


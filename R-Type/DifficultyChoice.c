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
#include "DifficultyChoice.h"

int DifficultyCocheX = 460;

SDL_Rect CocheDifficulty(int x)
{
    SDL_Rect button1 = { x, 305, 20, 20 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button1);

    return button1;
}

SDL_Rect ButtonDifficultyOption1()
{
    SDL_Rect button1 = { 455, 300, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button1);

    return button1;
}
SDL_Rect ButtonDifficultyOption2()
{
    SDL_Rect button2 = { 680, 300, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button2);

    return button2;
}
SDL_Rect ButtonDifficultyOption3()
{
    SDL_Rect button3 = { 915, 300, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button3);

    return button3;
}

void ChoixDifficultee(int x, int y) 
{
    if (x > 455 && x < 485 && y > 300 && y < 330)
    {
        DifficultyCocheX = 460;
        // changer la difficultée ici
    }
    if (x > 680 && x < 710 && y > 300 && y < 330)
    {
        DifficultyCocheX = 685;
        // changer la difficultée ici
    }
    if (x > 915 && x < 945 && y > 300 && y < 330)
    {
        DifficultyCocheX = 920;
        // changer la difficultée ici
    }
}
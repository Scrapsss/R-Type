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
#include "SoundChoice.h"

int cocheX = 685;

SDL_Rect CocheVolume(int x)
{
    SDL_Rect button1 = { x, 205, 20, 20 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button1);

    return button1;
}

SDL_Rect ButtonSoundOption1()
{
    SDL_Rect button1 = {455, 200, 30, 30};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button1);

    return button1;
}
SDL_Rect ButtonSoundOption2()
{
    SDL_Rect button2 = { 680, 200, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button2);

    return button2;
}
SDL_Rect ButtonSoundOption3()
{
    SDL_Rect button3 = { 915, 200, 30, 30 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button3);

    return button3;
}


void ChoixSon(int x, int y)
{
    if (x > 455 && x < 485 && y > 200 && y < 230)
    {
        cocheX = 460;
        volumeSon = 125;
    }
    if (x > 680 && x < 710 && y > 200 && y < 230)
    {
        cocheX = 685;
        volumeSon = 120;
    }
    if (x > 915 && x < 945 && y > 200 && y < 230)
    {
        cocheX = 920;
        volumeSon = 110;
    }
}
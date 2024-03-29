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
#include "TextureManager.h"
#include <SDL_mixer.h>
#include "GameOver.h"

int volumeSon = 120;
Mix_Music* Ambiance = NULL;

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
                Reset();

                Ambiance = Mix_LoadMUS("C:/Users/ecampestrini/Desktop/R-Type/src/PromptoSong.mp3");
                Mix_VolumeMusic(MIX_MAX_VOLUME - volumeSon);
                Mix_PlayMusic(Ambiance, -1);
            }
            if (x > 700 && x < 1100 && y > 380 && y < 480)
            {
                Quit = 1;
            }
            if (x > 1020 && x < 1145 && y > 35 && y < 75)
            {
                isInMenu = 0;
                isInOption = 1;
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
    SDL_RenderCopy(renderer, logoTexture, NULL, &button);
    

    return button;
}

SDL_Rect ButtonQuit()
{
    SDL_Rect button = {700, 375, 400, 150};
    SDL_RenderCopy(renderer, buttonTexture, NULL, &button);

    return button;
}

SDL_Rect ButtonPlay()
{
    SDL_Rect button = { 100, 375, 400, 150 };
    SDL_RenderCopy(renderer, buttonTexture, NULL, &button);

    return button;
}
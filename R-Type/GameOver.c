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
#include "Collision.h"
#include <SDL_mixer.h>


void GameOver()
{
    Mix_Chunk* death = NULL;
    Mix_AllocateChannels(15);
    death = Mix_LoadMUS("C:/Users/elize/Documents/R-Type/src/PlayerDeath.mp3");
    Mix_VolumeChunk(death, MIX_MAX_VOLUME - volumeSon);
    Mix_PlayChannel(-1, death, 0);

    fond();
    Mix_HaltMusic();
    RetourMenu();
    ButtonRetourMenu();
    AfficherRetourMenu();
    AfficherGameOver();
    AfficherScore(renderer, scorePlayer1, font);
    AfficherStats(renderer, font);
    AfficherPourcentage();

    SDL_RenderPresent(renderer);

}


void RetourMenu()
{
    SDL_Event event;
    int x, y;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            Uint32 buttons = SDL_GetMouseState(&x, &y);
            if (x > 450 && x < 750 && y > 400 && y < 475)
            {
                isDead = 0;
                isInMenu = 1;
            }

        }
    }
}

SDL_Rect ButtonRetourMenu()
{
    SDL_Rect button = { 450, 400, 300, 75 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button);

    return button;
}

void AfficherRetourMenu() {
    SDL_Color textColor = { 255, 255, 255 };

    char gameOver[100];
    snprintf(gameOver, sizeof(gameOver), "Retour au menu");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, gameOver, textColor);
    if (surfaceMessage == NULL)
    {
        printf("Erreur lors du rendu du texte : %s\n", TTF_GetError());
    }
    else {
        SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        if (message == NULL)
        {
            printf("Erreur lors de la création de la texture du texte : %s\n", SDL_GetError());
        }
        else
        {
            SDL_Rect textRect = { 500, 425, surfaceMessage->w , surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

void AfficherGameOver() {
    SDL_Color textColor = { 255, 255, 255 };

    char gameOver[100];
    snprintf(gameOver, sizeof(gameOver), "GAME OVER ...");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, gameOver, textColor);
    if (surfaceMessage == NULL)
    {
        printf("Erreur lors du rendu du texte : %s\n", TTF_GetError());
    }
    else {
        SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        if (message == NULL)
        {
            printf("Erreur lors de la création de la texture du texte : %s\n", SDL_GetError());
        }
        else
        {
            SDL_Rect textRect = { 420, 80, surfaceMessage->w + 200 , surfaceMessage->h + 100};
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}
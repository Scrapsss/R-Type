#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "menuManager.h"
#include "WindowManager.h"
#include "TextMenu.h"
#include "ScoreManager.h"
#include "TextureManager.h"

void AfficherPlay() {
    SDL_Color textColor = { 0, 0, 0 }; // Couleur du texte (noir)

    char play[100];
    snprintf(play, sizeof(play), "PLAY");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, play, textColor);
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
            SDL_Rect textRect = { 190, 390, surfaceMessage->w + 150, surfaceMessage->h + 70 };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}


void AfficherQuit() {
    SDL_Color textColor = { 0, 0, 0 }; // Couleur du texte (noir)

    char Quit[100];
    snprintf(Quit, sizeof(Quit), "Quit");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, Quit, textColor);
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
            SDL_Rect textRect = { 800, 390, surfaceMessage->w + 150, surfaceMessage->h + 70 };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

SDL_Rect fond()
{
    SDL_Rect button = { 0, 0, 1200, 600 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button);

    return button;
}

void AfficherOption() {
    SDL_Color textColor = { 0, 0, 0 }; 

    char option[100];
    snprintf(option, sizeof(option), "Options");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, option, textColor);
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
            SDL_Rect textRect = { 1030, 40, surfaceMessage->w , surfaceMessage->h  };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

SDL_Rect ButtonOption()
{
    SDL_Rect button = { 1020, 35, 125, 40 };
    SDL_RenderCopy(renderer, buttonTexture, NULL, &button);

    return button;
}
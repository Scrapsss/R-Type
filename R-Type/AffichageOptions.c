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


void AfficherOptionSon() {
    SDL_Color textColor = { 255, 255, 255 };

    char volume[200];
    snprintf(volume, sizeof(volume), "Music Volume :                                 option 1               option 2                option 3");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, volume, textColor);
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
            SDL_Rect textRect = { 35, 200, surfaceMessage->w , surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

void AfficherOptionDificultee() {
    SDL_Color textColor = { 255, 255, 255 };

    char volume[200];
    snprintf(volume, sizeof(volume), "Difficulty :                                      Easy                     Normal                 Hard");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, volume, textColor);
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
            SDL_Rect textRect = { 35, 300, surfaceMessage->w , surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}
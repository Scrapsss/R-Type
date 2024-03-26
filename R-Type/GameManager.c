#include <SDL_ttf.h>
#include <SDL.h>
#include <stdio.h>
#include "WindowManager.h"
#include "ScoreManager.h"
#include "GameManager.h"

// On initialise la vie du joueur à 3
Player1Life = 3;



// Affichage de le vie du juoueur :
void AfficherVie(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 0, 0, 0 }; // Couleur du texte (noir)

    char scoreText[100];
    snprintf(scoreText, sizeof(scoreText), "Vies    :    %d", Player1Life);

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, scoreText, textColor);
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
            SDL_Rect textRect = { 50, 20, surfaceMessage->w, surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}
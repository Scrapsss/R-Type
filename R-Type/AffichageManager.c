#include <stdio.h>
#include "WindowManager.h"
#include "ScoreManager.h"
#include "GameManager.h"
#include "Collision.h"
#include "AffichageManager.h"
#include "Movement.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include "ennemiManager.h"


// On initialise la vie du joueur à 3
Player1Life = 0;

void Afichage()
{
    AfficherBordure();
    AfficherVie(renderer, font);
    AfficherNiveau(renderer, font);
    AfficherScore(renderer, scorePlayer1, font);
    AfficherStats(renderer, font);
    AfficherPourcentage();
}

// Affichage de le vie du joueur :
void AfficherVie(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255 }; // Couleur du texte (blanc)

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

// Affichage du niveau :
void AfficherNiveau(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255 }; // Couleur du texte (blanc)

    char scoreText[100];
    snprintf(scoreText, sizeof(scoreText), "Niveau    :    %d", niveauActuel);

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
            SDL_Rect textRect = { 560, 525, surfaceMessage->w + 6, surfaceMessage->h + 6 };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

// Affichage des stats :
void AfficherStats(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255}; // Couleur du texte (blanc)

    char scoreText[100];

    if (PlayerDeathState == 1)
    {
        compteurFrame = kmBeforeVague;
    }
    snprintf(scoreText, sizeof(scoreText), "Shots Fired    :    %d            Kills    :    %d            km    :    %d", nbTirs, scorePlayer1 / 5, compteurFrame / 300);

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
            SDL_Rect textRect = { 230, 570, surfaceMessage->w, surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

void AfficherBordure()
{
    SDL_Rect bordureHaute = { 0, 0, 1200, 50 };
    SDL_Rect bordureBasse = { 0, 525, 1200, 125 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &bordureHaute);
    SDL_RenderFillRect(renderer, &bordureBasse);
}


#include <stdio.h>
#include "WindowManager.h"
#include "ScoreManager.h"
#include "GameManager.h"
#include "Collision.h"
#include "AffichageManager.h"
#include "Movement.h"
#include <SDL_ttf.h>
#include <SDL.h>



// On initialise la vie du joueur à 3
Player1Life = 0;

void Afichage()
{
    AfficherVie(renderer, font);
    AfficherNiveau(renderer, font);
    AfficherScore(renderer, scorePlayer1, font);
    AfficherStats(renderer, font);
}

// Affichage de le vie du joueur :
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

// Affichage du niveau :
void AfficherNiveau(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 0, 0, 0 }; // Couleur du texte (noir)

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
            SDL_Rect textRect = { 560, 500, surfaceMessage->w + 6, surfaceMessage->h + 6 };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

// Affichage des stats :
void AfficherStats(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 0, 0, 0 }; // Couleur du texte (noir)

    char scoreText[100];
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
            SDL_Rect textRect = { 420, 570, surfaceMessage->w, surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}
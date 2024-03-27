#include <SDL_ttf.h>
#include <SDL.h>
#include <stdio.h>
#include "WindowManager.h"
#include "ScoreManager.h"
#include "AffichageManager.h"

void TextInitializer()
{
    if (InitTTF() == 0) {
        font = LoadFont();
    }
    if (font == NULL) {
        // Gérer l'erreur, par exemple quitter le programme
        printf("Erreur lors du chargement de la police\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1; // Ou tout autre code d'erreur approprié
    }
}

// Initialisation du texte
int InitTTF() {
    if (TTF_Init() == -1) {
        printf("Failed to load SDL_ttf : %s\n", TTF_GetError());
        return -1;
    }
    return 0;
}

// Fonction pour charger la police
TTF_Font* LoadFont() {
    font = TTF_OpenFont("C:/Users/Scrap/Documents/Font/GODOFWAR.ttf", 24);
    if (font == NULL) {
        printf("Erreur lors du chargement de la police : %s\n", TTF_GetError());
        return NULL;
    }
    return font;
}

void AfficherScore(SDL_Renderer* renderer, int scorePlayer1, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255 }; // Couleur du texte (blanc)

    char scoreText[100];
    snprintf(scoreText, sizeof(scoreText), "SCORE : %d", scorePlayer1);

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, scoreText, textColor);
    if (surfaceMessage == NULL) {
        printf("Erreur lors du rendu du texte : %s\n", TTF_GetError());
    }
    else {
        SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        if (message == NULL) {
            printf("Erreur lors de la création de la texture du texte : %s\n", SDL_GetError());
        }
        else {
            SDL_Rect textRect = { 575, 20, surfaceMessage->w, surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}
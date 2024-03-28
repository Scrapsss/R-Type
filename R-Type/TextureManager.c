#include "WindowManager.h"
#include "TextureManager.h"
#include "AffichageManager.h"


void SetTexture()
{
    //Creation des textures joueur
    shipSurface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/prompto.bmp");
    shipTexture = SDL_CreateTextureFromSurface(renderer, shipSurface);
    SDL_FreeSurface(shipSurface);

    // Ennemi
    ennemiSurface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/pampa.bmp");
    ennemiTexture = SDL_CreateTextureFromSurface(renderer, ennemiSurface);
    SDL_FreeSurface(ennemiSurface);

    // Terrain
    terrainSurface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/herbe.bmp");
    terrainTexture = SDL_CreateTextureFromSurface(renderer, terrainSurface);
    SDL_FreeSurface(terrainSurface);

    // Projectiles
    tirSurface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/bullet.bmp");
    tirTexture = SDL_CreateTextureFromSurface(renderer, tirSurface);
    SDL_FreeSurface(tirSurface);
    
    // Boutons
    buttonSurface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/button.bmp");
    buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
    SDL_FreeSurface(buttonSurface);

    // logo
    logoSurface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/logo.bmp");
    logoTexture = SDL_CreateTextureFromSurface(renderer, logoSurface);
    SDL_FreeSurface(logoSurface);
}

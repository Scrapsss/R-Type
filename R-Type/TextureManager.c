#include "WindowManager.h"
#include "TextureManager.h"
#include "AffichageManager.h"
#include "Collision.h"

SDL_Rect explosionFrames[5];

void SetTexture()
{
    TextureGame();
    TableauExplosion();
    TableauExplosion();
}

void TextureExplosion()
{
    explosion1Surface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/explosion.bmp");
    explosion1Texture = SDL_CreateTextureFromSurface(renderer, explosion2Surface);
    SDL_FreeSurface(explosion1Surface);

    explosion2Surface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/explosion1.bmp");
    explosion2Texture = SDL_CreateTextureFromSurface(renderer, explosion2Surface);
    SDL_FreeSurface(explosion2Surface);

    explosion3Surface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/explosion2.bmp");
    explosion3Texture = SDL_CreateTextureFromSurface(renderer, explosion3Surface);
    SDL_FreeSurface(explosion3Surface);

    explosion4Surface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/explosion3.bmp");
    explosion4Texture = SDL_CreateTextureFromSurface(renderer, explosion4Surface);
    SDL_FreeSurface(explosion4Surface);

    explosion5Surface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/explosion4.bmp");
    explosion5Texture = SDL_CreateTextureFromSurface(renderer, explosion5Surface);
    SDL_FreeSurface(explosion5Surface);
}

void TextureGame()
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

void TableauExplosion()
{
    SDL_Rect explo1 = { 250, 300, 700, 250 };
    SDL_RenderCopy(renderer, explosion1Texture, NULL, &explo1);
    explosionFrames[0] = explo1;

    SDL_Rect explo2 = { 250, 300, 700, 250 };
    SDL_RenderCopy(renderer, explosion2Texture, NULL, &explo2);
    explosionFrames[0] = explo2;

    SDL_Rect explo3 = { 250, 300, 700, 250 };
    SDL_RenderCopy(renderer, explosion3Texture, NULL, &explo3);
    explosionFrames[0] = explo3;

    SDL_Rect explo4 = { 250, 300, 700, 250 };
    SDL_RenderCopy(renderer, explosion4Texture, NULL, &explo4);
    explosionFrames[0] = explo4;

    SDL_Rect explo5 = { 250, 300, 700, 250 };
    SDL_RenderCopy(renderer, explosion5Texture, NULL, &explo5);
    explosionFrames[0] = explo5;

}
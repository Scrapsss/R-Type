#include "WindowManager.h"
#include "TextureManager.h"
#include "AffichageManager.h"
#include "Collision.h"


void SetTexture()
{
    TextureGame();
    TableauExplosion();
    TextureExplosion();
}

void TextureExplosion()
{
    explosion1Surface = SDL_LoadBMP("C:/Users/elize/Documents/R-Type/src/explosion.bmp");
    explosion1Texture = SDL_CreateTextureFromSurface(renderer, explosion1Surface);
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
    explosionFrames[0] = explosion1Texture;
    explosionFrames[1] = explosion2Texture;
    explosionFrames[2] = explosion3Texture;
    explosionFrames[3] = explosion4Texture;
    explosionFrames[4] = explosion5Texture;
}
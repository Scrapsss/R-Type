#pragma once
SDL_Surface* shipSurface;
SDL_Texture* shipTexture;

SDL_Surface* ennemiSurface;
SDL_Texture* ennemiTexture;

SDL_Surface* terrainSurface;
SDL_Texture* terrainTexture;

SDL_Surface* tirSurface;
SDL_Texture*  tirTexture;

SDL_Surface* buttonSurface;
SDL_Texture* buttonTexture;

SDL_Surface* logoSurface;
SDL_Texture* logoTexture;

void TableauExplosion();
void TextureGame();
void SetTexture();
void TextureExplosion();

SDL_Rect explosionFrames[5];


// les images de l'explosion :
SDL_Surface* explosion1Surface;
SDL_Texture* explosion1Texture;

SDL_Surface* explosion2Surface;
SDL_Texture* explosion2Texture;

SDL_Surface* explosion3Surface;
SDL_Texture* explosion3Texture;

SDL_Surface* explosion4Surface;
SDL_Texture* explosion4Texture;

SDL_Surface* explosion5Surface;
SDL_Texture* explosion5Texture;


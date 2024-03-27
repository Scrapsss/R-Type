#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setShip.h"
#include "TextureManager.h"

SDL_Rect setShip(int posX, int posY, int SizeX, int SizeY)
{
    SDL_Rect rect = { posX, posY, SizeX, SizeY };
    SDL_RenderCopy(renderer, shipTexture, NULL, &rect);

    return rect;
}
#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setShip.h"

SDL_Rect setShip(int posX, int posY, int SizeX, int SizeY)
{
    SDL_Rect rect = { posX, posY, SizeX, SizeY };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    return rect;
}
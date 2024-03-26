#include <SDL.h>
#include <stdio.h>
#include "Movement.h"
#include "TirManager.h"

// Déclaration de la position du joueur
int playerX = 100;
int playerY = 300;

// Déclaration de la vitesse du joueur
int playerDx = 0;
int playerDy = 0;

int compteur = 0;

void KeyDownCheck(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
        playerDy = -7;
        break;
    case SDLK_DOWN:
        playerDy = 7;
        break;
    case SDLK_RIGHT:
        playerDx = 7;
        break;
    case SDLK_LEFT:
        playerDx = -7;
        break;
    case SDLK_SPACE:

        compteur = ProjectileManager(compteur);
        break;

    default:
        break;
    }
}

void KeyUpCheck(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
    case SDLK_DOWN:
        playerDy = 0;
        break;
    case SDLK_LEFT:
    case SDLK_RIGHT:
        playerDx = 0;
        break;
    default:
        break;
    }
}

void ShipManager()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            KeyDownCheck(event);
            break;
        case SDL_KEYUP:
            KeyUpCheck(event);
            break;
        }
    }
}

void UpdatePos()
{
    playerX += playerDx;
    playerY += playerDy;
}
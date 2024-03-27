#include <SDL.h>
#include <stdio.h>
#include "Movement.h"
#include "TirManager.h"
#include "ennemiManager.h"

// Déclaration de la position du joueur
int playerX = 100;
int playerY = 300;

// Déclaration de la vitesse du joueur
int playerDx = 7;
int playerDy = 7;

int StateUp = 0;
int StateDown = 0;
int StateLeft = 0;
int StateRight = 0;
int StateSpace = 0;

int compteur = 0;
int compteurFrame = 0;

int Quit = 0;

void KeyDownCheck(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_UP)
    {
        StateUp = 1;
    }

    if (event.key.keysym.sym == SDLK_DOWN)
    {
        StateDown = 1;
    }

    if (event.key.keysym.sym == SDLK_RIGHT)
    {
        StateRight = 1;
    }

    if (event.key.keysym.sym == SDLK_LEFT)
    {
        StateLeft = 1;
    }

    if (event.key.keysym.sym == SDLK_SPACE)
    {
        StateSpace = 1;
    }

    if (event.key.keysym.sym == SDLK_ESCAPE)
    {
        Quit = 1;
    }
}

void KeyUpCheck(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_UP)
    {
        StateUp = 0;
    }

    if (event.key.keysym.sym == SDLK_DOWN)
    {
        StateDown = 0;
    }
    if (event.key.keysym.sym == SDLK_LEFT)
    {
        StateLeft = 0;
    }

    if (event.key.keysym.sym == SDLK_RIGHT)
    {
        StateRight = 0;
    }

    if (event.key.keysym.sym == SDLK_SPACE)
    {
        StateSpace = 0;
    }

}

void ShipManager()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        
        
        if (event.type == SDL_KEYDOWN)
        {
            KeyDownCheck(event);
        }
        if (event.type == SDL_KEYUP)
        {
            KeyUpCheck(event);
        }
    }

    if (StateSpace == 1)
    {
        if (compteurFrame % 8 == 1)
        {
            compteur = ProjectileManager(compteur);
        }
    }
}

void UpdatePos()
{
    if (playerY <= 0)
    {
        StateUp = 0;
    }

    if (playerY >= 600 - 25)
    {
        StateDown = 0;
    }

    if (playerX <= 0)
    {
        StateLeft = 0;
    }

    if (playerX >= 1200 - 50)
    {
        StateRight = 0;
    }

    playerX += playerDx * (StateRight - StateLeft);
    playerY += playerDy * (StateDown - StateUp);
    UpdateEnnemiPosition();
}
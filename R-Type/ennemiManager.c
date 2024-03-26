#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "Movement.h"
#include "TirManager.h"
#include "ennemiManager.h"
#include <stdlib.h>
#include <time.h>

// D�claration de la position des ennemis
int ennemiX;
int ennemiY;

int compteurEnnemi = 0;
int nbEnnemis = 10;

// Fonction qui cr�e et affiche les ennemis
SDL_Rect setEnnemi()
{
    ennemiY = (rand() % (500));
    ennemiX = (rand() % (300));

    SDL_Rect ennemi = { ennemiX+1400, ennemiY, 30, 30 };
    return ennemi;
}

int EnnemiManager()
{
    while (compteurEnnemi < nbEnnemis)
    {
            ennemiListe[compteurEnnemi] = setEnnemi();
            compteurEnnemi += 1; 
    }

    return compteurEnnemi;
}

void UpdateEnnemiPosition()
{
    for (int i = 0; i < nbEnnemis; i++)
    {
        ennemiListe[i].x -= 3;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &ennemiListe[i]);
    }
}

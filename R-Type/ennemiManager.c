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
int nbEnnemis = 5;

// Fonction qui cr�e et affiche les ennemis
SDL_Rect setEnnemi()
{
    srand(time(NULL));
    ennemiY = (rand() % (500 - 100));

    SDL_Rect ennemi = { 1300, 400 , 20, 10 };
    return ennemi;
}

int EnnemiManager()
{

    if (compteurEnnemi < nbEnnemis)
    {
        ennemiListe[compteurEnnemi] = setEnnemi();
        compteurEnnemi += 1;
    }
    else {
        compteurEnnemi = 0;
    }

    return compteurEnnemi;
}

void UpdateEnnemiPosition()
{
    for (int i = 0; i < nbEnnemis; i++)
    {
        ennemiListe[i].x -= 12;
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &ennemiListe[i]);
    }
}

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
int compteurliste = 0;
int nbEnnemis = 5;
int vitesseEnnemi = 1;

// Fonction qui cr�e et affiche les ennemis
SDL_Rect setEnnemi()
{
    ennemiY = (rand() % (500));
    ennemiX = (rand() % (500));

    SDL_Rect ennemi = { ennemiX+1400, ennemiY, 30, 30 };
    return ennemi;
}

int EnnemiManager(int nbEnnemis)
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
    if (ennemiListe != NULL)
    {
        for (int i = 0; i < nbEnnemis; i++)
        {
            if (ennemiListe[i].w == 0)
            {
                continue;
            }

            if (ennemiListe[i].x < 0)
            {
                ennemiListe[i].w = 0;
                continue;
            }

            ennemiListe[i].x -= vitesseEnnemi;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderFillRect(renderer, &ennemiListe[i]);
        }
        for (int j = 0; j < nbEnnemis; j++)
        {
            if (ennemiListe[j].w == 0)
            {
                compteurliste += 1;
            }
        }

        if (compteurliste == nbEnnemis)
        {
            compteurEnnemi = 0;
            if (nbEnnemis >= 90)
            {
                EnnemiManager(nbEnnemis);
            }
            else
            {
                EnnemiManager(nbEnnemis += 5);
                if (vitesseEnnemi < 3)
                {
                    vitesseEnnemi += 1;
                }
            }
        }
        compteurliste = 0;
    }  
}

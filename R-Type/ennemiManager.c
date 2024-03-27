﻿#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "Movement.h"
#include "TirManager.h"
#include "ennemiManager.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "GameManager.h"
#include "AffichageManager.h"

// D�claration de la position des ennemis
int ennemiX;
int ennemiY;

int compteurEnnemi = 0;
int compteurliste = 0;
int nbEnnemis = 5;
int vitesseEnnemi = 1;

niveauActuel = 1;
int compteurVague = 0;

// Fonction qui cr�e et affiche les ennemis
SDL_Rect setEnnemi()
{
    ennemiY = (rand() % (500));
    ennemiX = (rand() % (500));

    SDL_Rect ennemi = { ennemiX+1400, ennemiY, 30, 30 };
    return ennemi;
}

int EnnemiManager()
{
   
    while (compteurEnnemi < 100)
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
        DeplacementEnnemi();

        if (compteurliste == nbEnnemis)
        {
            compteurVague += 1;
            if (compteurVague % 3 == 0)
            {
                niveauActuel += 1;
                nbEnnemis = 5;
            }

            compteurEnnemi = 0;
            if (nbEnnemis >= 90)
            {
                EnnemiManager();
            }
            else
            {
                nbEnnemis += 5;
                EnnemiManager();
                if (vitesseEnnemi < 3)
                {
                    vitesseEnnemi += 1;
                }
            }
        }
        compteurliste = 0;
    }  
}

void DeplacementEnnemi()
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

        ennemiListe[i].x -= 3;
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
}
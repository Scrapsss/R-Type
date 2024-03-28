#include <stdio.h>
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
#include "Collision.h"
#include "TextureManager.h"
#include "DifficultyChoice.h"

// D�claration de la position des ennemis
int ennemiX;
int ennemiY;

int compteurEnnemi = 0;
int compteurliste = 0;
int nbEnnemis = 0;
float vitesseEnnemi = 2;

niveauActuel = 1;
int compteurVague = 0;
int kmBeforeVague = 0;


// Fonction qui cr�e et affiche les ennemis
SDL_Rect setEnnemi()
{
    ennemiY = (rand() % (250));
    ennemiX = (rand() % (500));

    SDL_Rect ennemi = { ennemiX+1400, ennemiY+150, 40, 40 };

    kmBeforeVague = compteurFrame;

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
            if (PlayerDeathState == 0)
            {
                compteurVague += 1;
            }

            if (compteurVague % 3 == 0 && compteurVague != 0)
            {
                compteurVague = 0;
                niveauActuel += 1;
                nbEnnemis = 0;
                if (vitesseEnnemi < 2000)
                {
                   
                    vitesseEnnemi += difficulteSpeed;
                }
            }

            compteurEnnemi = 0;
            if (nbEnnemis >= 90 || PlayerDeathState == 1)
            {
                PlayerDeathState = 0;
                EnnemiManager();
            }
            else
            {
                nbEnnemis += difficulteMob;
                EnnemiManager();
                
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

        ennemiListe[i].x -= vitesseEnnemi;
        SDL_RenderCopy(renderer, ennemiTexture, NULL, &ennemiListe[i]);
    }
    for (int j = 0; j < nbEnnemis; j++)
    {
        if (ennemiListe[j].w == 0)
        {
            compteurliste += 1;
        }
    }
}
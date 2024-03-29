#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "Movement.h"
#include "TirManager.h"
#include <stdlib.h>
#include "TextureManager.h"

// D�claration de la position des projectiles
int projectileX;
int projectileY;

nbTirs = 0;

// Fonction qui cr�e et affiche les projectiles
SDL_Rect setProjectiles()
{ 
    SDL_Rect projectile = {playerX + 50, playerY + 8, 20, 10};
    nbTirs += 1;

    return projectile;
}

int ProjectileManager(int compteur)
{

    if (compteur < 100)
    {
        projectilesListe[compteur] = setProjectiles();
        compteur += 1;
    }
    else {
        compteur = 0;
    }

    return compteur;
}

void UpdateTirPosition()
{
    if (projectilesListe != NULL)
    {
        for (int i = 0; i < 100; i++)
        {
            if (projectilesListe[i].w == 0)
            {
                continue;
            }

            if (projectilesListe[i].x >= 1200 - projectilesListe[i].w)
            {
                projectilesListe[i].w = 0;
                continue;
            }

            projectilesListe[i].x += 12;
            
            SDL_RenderCopy(renderer, tirTexture, NULL, &projectilesListe[i]);
        }
    }
    
}
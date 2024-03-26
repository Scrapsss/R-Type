#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "Movement.h"
#include "TirManager.h"
#include <stdlib.h>

// D�claration de la position des projectiles
int projectileX;
int projectileY;



// Fonction qui cr�e et affiche les projectiles
SDL_Rect setProjectiles()
{ 
    SDL_Rect projectile = {playerX + 50, playerY, 20, 10};
    
    //SDL_RenderFillRect(renderer, &projectile);

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
    for (int i = 0; i < 100; i++)
    {
        projectilesListe[i].x += 12;
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &projectilesListe[i]);
        if (projectilesListe[i].x > 1200)
        {
            
        }
    }
}

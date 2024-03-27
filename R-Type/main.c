#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setShip.h"
#include "Movement.h"
#include "TirManager.h"
#include "ennemiManager.h"
#include "Collision.h"
#include "ScoreManager.h"
#include "GameManager.h"
#include "AffichageManager.h"
#include "menuManager.h"
#include <SDL_image.h>
#include "TextureManager.h"


int main()
{  
    Initializer(); 
    TextInitializer();
    SetTexture();

    while (1)
    {
        if (Quit == 1)
        {
            break;
        }

        WhereIsThePlayer();
        

        while (Player1Life != 0)
        {
            srand(time(NULL));
            ClearScreen();

            
            SDL_RenderCopy(renderer, terrainTexture, NULL, NULL);

            ShipManager();
            playerShip = setShip(playerX, playerY, 50, 50);

            UpdateTirPosition();
            UpdatePos();
        
            CheckCollisions();
            CollisionWithShip();

            Afichage(); // Fonction qui appelle toutes les fonctions d'affichage
            
            
            SDL_RenderPresent(renderer);
            compteurFrame += 1;
            SDL_Delay(10);

            if (Quit == 1)
            {
                break;
            }
    
        }
        niveauActuel = 1;
        nbTirs = 0;
        scorePlayer1 = 0;
        compteurFrame = 0;
        ClearScreen();
    }

    return 0;
}

void WhereIsThePlayer()
{
    if (isInMenu == 1)
    {
        ButtonMenu();
        Buttons();
    }
    if (isInOption == 1)
    {
        // afficher les options
    }
}
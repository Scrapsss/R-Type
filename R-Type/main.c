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
#include <SDL_mixer.h>


int main()
{
    Initializer(); 
    TextInitializer();

    while (1)
    {
        if (Quit == 1)
        {
            break;
        }

        ButtonMenu();
        Buttons();

        


        while (Player1Life != 0)
        {
            srand(time(NULL));
            ClearScreen();

            ShipManager();
            playerShip = setShip(playerX, playerY, 50, 25);
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
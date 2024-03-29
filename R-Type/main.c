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
#include "TextureManager.h"
#include "GameOver.h"

Mix_Music* death = NULL;

void WhereIsThePlayer()
{
    if (isInMenu == 1)
    {
        ButtonMenu();
        Buttons();
    }
    if (isInOption == 1)
    {
        Options();
        // afficher les options
    }
    if (isDead == 1)
    {
        GameOver();
    }
}

void Jeu()
{
    SDL_RenderCopy(renderer, terrainTexture, NULL, NULL);

    ShipManager();
    playerShip = setShip(playerX, playerY, 65, 50);

    UpdatePos();

    Afichage(); // Fonction qui appelle toutes les fonctions d'affichage

    CheckCollisions();
    CollisionWithShip();
}

void MenuCheck()
{
    if (isInMenu == 0 && isInOption == 0)
    {
        isDead = 1;
    }
}

int main()
{  
    isInMenu = 1;
    Initializer(); 
    
    while (1)
    {
        if (Quit == 1)
        {
            break;
        }

        WhereIsThePlayer();
        
        while (Player1Life != 0)
        {
            isInMenu = 0;
            srand(time(NULL));
            ClearScreen();
            Jeu();
            
            SDL_RenderPresent(renderer);
            compteurFrame += 1;
            SDL_Delay(10);
        }
        MenuCheck();
        
        ClearScreen();
    }
    return 0;
}


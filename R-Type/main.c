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

int main()
{
    Initializer(); 
    TextInitializer();


    while (1)
    {
        srand(time(NULL));
        ClearScreen();


        ShipManager();
        UpdatePos();
        playerShip = setShip(playerX, playerY, 50, 25);


        UpdateTirPosition();
        EnnemiManager();
        UpdateEnnemiPosition();

        CheckCollisions();
        CollisionWithShip();

        AfficherScore(renderer, scorePlayer1, font);
        AfficherVie(renderer, font);

        SDL_RenderPresent(renderer);
        compteurFrame += 1;
        SDL_Delay(10);
    
    }
    return 0;
}
#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setShip.h"
#include "Movement.h"
#include "TirManager.h"
#include "ennemiManager.h"

int main()
{
    Initializer(); 
    


    while (1)
    {
        srand(time(NULL));
        ClearScreen();


        ShipManager();
        UpdatePos();
        SDL_Rect playerShip = setShip(playerX, playerY, 50, 25);


        UpdateTirPosition();
        EnnemiManager();
        UpdateEnnemiPosition();
        SDL_RenderPresent(renderer);
        compteurFrame += 1;
        SDL_Delay(10);

        
    }

    return 0;
}
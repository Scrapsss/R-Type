#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setShip.h"
#include "Movement.h"
#include "TirManager.h"

int main()
{
    Initializer();

    while (1)
    {
        ClearScreen();


        ShipManager();
        UpdatePos();
        SDL_Rect playerShip = setShip(playerX, playerY, 50, 25);


        if (projectilesListe != NULL)
        {
            UpdateTirPosition();
        }


        SDL_RenderPresent(renderer);
        compteurFrame += 1;
        SDL_Delay(10);

        
    }

    return 0;
}
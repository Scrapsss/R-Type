#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include "ennemiManager.h"
#include "TirManager.h"
#include "GameManager.h"
#include "AffichageManager.h"
#include "Collision.h"
#include "Movement.h"
#include "TextureManager.h"
#include "WindowManager.h"

scorePlayer1 = 0;
int PlayerDeathState = 0;

SDL_Texture* explosionFrames[5];

void CheckCollisions()
{
	if (projectilesListe != NULL && ennemiListe != NULL)
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				SDL_bool collision = SDL_HasIntersection(&projectilesListe[i], &ennemiListe[j]);

				if (collision)
				{
					
					Mix_Music* explosion2 = NULL;
					Mix_AllocateChannels(15);
					explosion2 = Mix_LoadWAV("C:/Users/elize/Documents/R-Type/src/Bounce.wav");
					
					// Affichage de l'explosion
					for (int k = 0; k < 5; k++)
					{
						SDL_Rect button = { ennemiListe[j].x, ennemiListe[j].y, 40, 40 };
						SDL_RenderCopy(renderer, explosionFrames[k], NULL, &(SDL_Rect){ennemiListe[j].x, ennemiListe[j].y, 40, 40});
						SDL_RenderPresent(renderer);
					}

					Mix_PlayChannel(-1, explosion2, 0);
					projectilesListe[i].w = 0;
					ennemiListe[j].w = 0;
					scorePlayer1 += 5;

					

				}
			}
		}
	}
}

void CollisionWithShip()
{
	if (ennemiListe != NULL)
	{
		for (int i = 0; i < 100; i++)
		{
			SDL_bool collisionShip = SDL_HasIntersection(&ennemiListe[i], &playerShip);
			if (collisionShip)
			{
				Player1Life -= 1;
				PlayerDeathState = 1;
				playerX = 100;
				playerY = 300;
				SDL_Delay(1000);
				for (int j = 0; j < 100; j++)
				{
					ennemiListe[j].w = 0;
				}
			}
		}
	}
	
}
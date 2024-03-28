#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include "ennemiManager.h"
#include "TirManager.h"
#include "GameManager.h"
#include "AffichageManager.h"
#include "Collision.h"
#include "Movement.h"

scorePlayer1 = 0;
int PlayerDeathState = 0;

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
					Mix_Music* explosion = NULL;
					Mix_Music* explosion2 = NULL;
					explosion = Mix_LoadMUS("C:/Users/elize/Documents/R-Type/src/explosion_11.mp3");
					explosion2 = Mix_LoadMUS("C:/Users/elize/Documents/R-Type/src/explosion_11.mp3");
					Mix_PlayMusic(explosion, 1);
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
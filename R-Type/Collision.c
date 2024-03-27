#include <SDL.h>
#include <stdio.h>
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
#include <SDL.h>
#include <stdio.h>
#include "ennemiManager.h"
#include "TirManager.h"

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
				}
			}
		}
	}
}
#pragma once
#include <stdbool.h>
#include <SDL_ttf.h>
#include <SDL.h>

void AfficherVie(SDL_Renderer* renderer, TTF_Font* font);

SDL_Rect playerShip;
int Player1Life;


// Variables statistiques de partie :


int nbTirs; // Nb de projectiles lancés 

// Nb km parcouru (on peut utiliser compteurFrame)
// Nb d'ennemis vaincus (on peut utiliser le score)
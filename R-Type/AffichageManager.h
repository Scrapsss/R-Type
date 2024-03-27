#pragma once
#include <stdbool.h>
#include <SDL_ttf.h>
#include <SDL.h>

void AfficherVie(SDL_Renderer* renderer, TTF_Font* font);
void Afichage();
void AfficherNiveau(SDL_Renderer* renderer, TTF_Font* font);
void AfficherStats(SDL_Renderer* renderer, TTF_Font* font);
void AfficherBordure();

SDL_Rect playerShip;
int Player1Life;
niveauActuel;

// Variables statistiques de partie :

int nbTirs; // Nb de projectiles lancés 

// Nb km parcouru (on peut utiliser compteurFrame)
// Nb d'ennemis vaincus (on peut utiliser le score)
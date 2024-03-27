#pragma once
#include <SDL.h>

SDL_Rect ennemiListe[100]; // 10 est le nombre maximum d'ennemi
SDL_Rect setEnnemi();
int EnnemiManager();
void UpdateEnnemiPosition();
void DeplacementEnnemi();
extern int compteurVague;
extern int nbEnnemis;
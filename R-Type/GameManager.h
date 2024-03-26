#pragma once
#include <stdbool.h>
#include <SDL_ttf.h>
#include <SDL.h>

void AfficherVie(SDL_Renderer* renderer, TTF_Font* font);
SDL_Rect playerShip;
int Player1Life;
bool hasTouchedShip;
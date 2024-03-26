#pragma once
#include <SDL_ttf.h>
#include <SDL.h>

TTF_Font* font;
void TextInitializer();
int InitTTF();
TTF_Font* LoadFont();
void AfficherScore(SDL_Renderer* renderer, int scorePlayer1, TTF_Font* font);
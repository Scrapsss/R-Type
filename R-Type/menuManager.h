#pragma once
#include <SDL_mixer.h>

void ButtonMenu();
void Buttons();
SDL_Rect ButtonQuit();
SDL_Rect ButtonPlay();
SDL_Rect ButtonLogo();
SDL_Rect ButtonOption();
void WhereIsThePlayer();
extern volumeSon;

extern Mix_Music* Ambiance;
#pragma once
int cocheInputX;
SDL_Rect CocheInput(int x);
void ChoixInput(int x, int y, SDL_Event event);
void AfficherChoixInput();
void AfficherInput();
int KeyDownCheckInput();

int toucheGauche;
int toucheDroite;
int toucheHaut;
int toucheBas;
int toucheTir;
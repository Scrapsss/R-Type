#pragma once

// D�claration de la position du joueur
extern int playerX;
extern int playerY;

// D�claration de la vitesse du joueur
extern int playerDx;
extern int playerDy;
extern int Quit;

extern int compteurFrame;

void KeyDownCheck(SDL_Event event);
void KeyUpCheck(SDL_Event event);
void ShipManager();
void UpdatePos();

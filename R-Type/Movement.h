#pragma once

// Déclaration de la position du joueur
extern int playerX;
extern int playerY;

// Déclaration de la vitesse du joueur
extern int playerDx;
extern int playerDy;
extern int Quit;


extern int StateUp;
extern int StateDown;
extern int StateLeft;
extern int StateRight;
extern int StateSpace;

extern int compteurFrame;

void KeyDownCheck(SDL_Event event);
void KeyUpCheck(SDL_Event event);
void ShipManager();
void UpdatePos();

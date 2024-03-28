#include <stdio.h>
#include "WindowManager.h"
#include "ScoreManager.h"
#include "GameManager.h"
#include "Collision.h"
#include "AffichageManager.h"
#include "Movement.h"
#include <SDL_ttf.h>
#include <SDL.h>

isInOption = 0; // se met a 1 quand on entre dans les options pour afficher les options et sortir du menu
isInMenu = 0; // on initialise a 1 pour entrer dans le menu au lancement du jeu
isDead = 0;
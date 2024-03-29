#include "WindowManager.h"
#include "TextMenu.h"
#include "ScoreManager.h"
#include <SDL_ttf.h>
#include "AffichageManager.h"
#include "Movement.h"
#include "GameOver.h"
#include "menuManager.h"
#include "GameManager.h"
#include "OptionsManager.h"
#include "SoundChoice.h"

int cocheInputX = 305;

toucheGauche = SDLK_LEFT;
toucheDroite = SDLK_RIGHT;
toucheHaut = SDLK_UP;
toucheBas = SDLK_DOWN;
toucheTir = SDLK_SPACE;




int KeyDownCheckInput()
{
    SDL_Event event;
    int touche;
    SDL_WaitEvent(&event);

    switch (event.type) {
    case SDL_KEYDOWN:

        touche = event.key.keysym.sym;
        return touche;
        break;
    }
}

SDL_Rect CocheInput(int x)
{
    SDL_Rect button1 = { x, 405, 20, 20 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button1);

    return button1;
}

void ChoixInput(int x, int y, SDL_Event event)
{
    if (x > 300 && x < 330 && y > 400 && y < 430)
    {
        cocheInputX = 305;
        toucheGauche = KeyDownCheckInput();

    }
    else if (x > 470 && x < 500 && y > 400 && y < 430)
    {
        cocheInputX = 475;
        toucheDroite = KeyDownCheckInput();

    }
    else if (x > 640 && x < 670 && y > 400 && y < 430)
    {
        cocheInputX = 645;
        toucheHaut = KeyDownCheckInput();
    }
    else if (x > 810 && x < 840 && y > 400 && y < 430)
    {
        cocheInputX = 815;
        toucheBas = KeyDownCheckInput();

    }
    else if (x > 980 && x < 1010 && y > 400 && y < 430)
    {
        cocheInputX = 985;
        toucheTir = KeyDownCheckInput();
    }
}

void AfficherChoixInput() {
    SDL_Color textColor = {255, 255, 255};

    char Touches[200];
    snprintf(Touches, sizeof(Touches), "Input :                          Gauche        Droite           Haut             Bas               Tir");

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, Touches, textColor);
    if (surfaceMessage == NULL)
    {
        printf("Erreur lors du rendu du texte : %s\n", TTF_GetError());
    }
    else {
        SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        if (message == NULL)
        {
            printf("Erreur lors de la création de la texture du texte : %s\n", SDL_GetError());
        }
        else
        {
            SDL_Rect textRect = { 50, 400, surfaceMessage->w , surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}
void AfficherInput() {
    SDL_Color textColor = {255, 255, 255};

    char gameOver[500];
    snprintf(gameOver, sizeof(gameOver), "%s             %s             %s             %s             %s", SDL_GetKeyName(toucheGauche), SDL_GetKeyName(toucheDroite), SDL_GetKeyName(toucheHaut), SDL_GetKeyName(toucheBas), SDL_GetKeyName(toucheTir));

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, gameOver, textColor);
    if (surfaceMessage == NULL)
    {
        printf("Erreur lors du rendu du texte : %s\n", TTF_GetError());
    }
    else {
        SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        if (message == NULL)
        {
            printf("Erreur lors de la création de la texture du texte : %s\n", SDL_GetError());
        }
        else
        {
            SDL_Rect textRect = { 303, 450, surfaceMessage->w , surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}
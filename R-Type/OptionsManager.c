#include <SDL.h>
#include <stdio.h>
#include "menuManager.h"
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
#include "DifficultyChoice.h"
#include "AffichageOptions.h"
#include "TextureManager.h"


void Options()
{
    fond();

    OptionsChoice();
    
    
    ButtonVersMenu();
    AfficherRetourVersMenu();
    
    ButtonSoundOption1();
    ButtonSoundOption2();
    ButtonSoundOption3();

    AfficherOptionSon();
    AfficherOptionDificultee();

    ButtonDifficultyOption1();
    ButtonDifficultyOption2();
    ButtonDifficultyOption3();

    CocheVolume(cocheX);
    CocheDifficulty(DifficultyCocheX);
    

    SDL_RenderPresent(renderer);
}

void OptionsChoice()
{
    SDL_Event event;
    int x, y;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            Uint32 buttons = SDL_GetMouseState(&x, &y);
            if (x > 30 && x < 250 && y > 20 && y < 65)
            {
                isInOption = 0;
                isInMenu = 1;
            }
            
            ChoixSon(x, y);
            ChoixDifficultee(x, y);

        }
    }
}

SDL_Rect ButtonVersMenu()
{
    SDL_Rect button = { 32, 21, 220, 45 };
    SDL_RenderCopy(renderer, buttonTexture, NULL, &button);

    return button;
}

void AfficherRetourVersMenu() {
    SDL_Color textColor = { 0, 0, 0 };

    char gameOver[100];
    snprintf(gameOver, sizeof(gameOver), "Back To Menu");

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
            SDL_Rect textRect = { 50, 30, surfaceMessage->w , surfaceMessage->h };
            SDL_RenderCopy(renderer, message, NULL, &textRect);

            // Libérer la surface et la texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
}

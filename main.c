#include <SDL2/SDL.h>
#include "fractal_generator.h"

int main(){
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,0,&window,&renderer);

    // SDL_SetRenderDrawColor(renderer,0,0,0,255);

    char imagename[30];

    for(int i = 0; i < 2000; i++){
        SDL_RenderClear(renderer);

        SDL_PumpEvents();

        render(renderer, ((iv2){.x = SCREEN_WIDTH, .y = SCREEN_HEIGHT}), ((v2){.x = 0.35 + (i * 0.00001), .y = 0.12 + (i * 0.0005)}));

        // SDL_RenderPresent(renderer);
        // SDL_Delay(10000);

        SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
        SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);

        sprintf(imagename,"animation/%d",i);
        SDL_SaveBMP(sshot, strcat(imagename,".bmp"));
        SDL_FreeSurface(sshot);

        printf("Iteration: %d\n",i);
    }

    return 0;    
}
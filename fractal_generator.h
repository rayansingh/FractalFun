#ifndef FRACTAL_GENERATOR
#define FRACTAL_GENERATOR

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define X_OFFSET (SCREEN_WIDTH/2)
#define Y_OFFSET (SCREEN_HEIGHT/2)

typedef struct int_vector2d {
    int x;
    int y;
} iv2;

typedef struct vector2d {
    double x;
    double y;
} v2;

void render(SDL_Renderer* renderer, iv2 render_size, v2 constant);

#endif

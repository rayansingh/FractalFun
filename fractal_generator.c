#include "fractal_generator.h"
#include <stdio.h>

v2 vec_add(v2 a, v2 b){
    return (v2){.x = (a.x + b.x), .y = (a.y + b.y)};
}

v2 vec_sub(v2 a, v2 b){
    return (v2){.x = (a.x - b.x), .y = (a.y - b.y)};
}

double vec_mag(v2 a){
    return a.x * a.x + a.y * a.y;
}

// Compute Zn^2 + C
v2 compute_next(v2 current, v2 constant){
    const double zr = current.x * current.x - current.y * current.y;
    const double zi = 2.0 * current.x * current.y;

    return vec_add((v2) {.x = zr, .y = zi},constant);
}

uint32_t compute_iterations(v2 initial, v2 constant, int32_t iterations){
    uint32_t i;
    v2 point = initial;

    for(i = 0; i < iterations && (vec_mag(point) < 4.0); i++){
        point = compute_next(point,constant);
    }

    return i;
}

void render(SDL_Renderer* renderer, iv2 render_size, v2 constant){
    const double scale = 1.0f / (((float)render_size.y) / 2.0f);

    for (int y = 0; y < render_size.y; ++y){
        for (int x = 0; x < render_size.x; ++x){
            const double px = ((float)x - ((float)render_size.x) / 2.0f) * scale;
            const double py = ((float)y - ((float)render_size.y) / 2.0f) * scale;

            const float iterations = compute_iterations((v2){px,py},constant, 255);

            SDL_SetRenderDrawColor(renderer,iterations,iterations,iterations,255);
            SDL_RenderDrawPoint(renderer,x,y);
        }
    }
}


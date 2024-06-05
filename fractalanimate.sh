rm movie.mp4
gcc main.c fractal_generator.c -lSDL2 -I fractal_generator.h -o fractal
./fractal
ffmpeg -i animation/%d.bmp -c:v libx264 -r 30 -pix_fmt yuv420p movie.mp4 <<< y
rm animation/*
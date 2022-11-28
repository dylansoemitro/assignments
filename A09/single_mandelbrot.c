#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "read_ppm.h"
#include "write_ppm.h"



int main(int argc, char* argv[]) {
  int size = 480;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;

  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> -b <ymin> -t <ymax>\n", argv[0]); break;
    }
  }
  printf("Generating mandelbrot with size %dx%d\n", size, size);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);

  // todo: your work here
  // generate pallet
  srand(time(0));
  struct ppm_pixel* pallet = malloc (sizeof(struct ppm_pixel) * maxIterations);
  for (int i = 0; i < maxIterations; i++) {
    pallet[i].red = rand() % 256;
    pallet[i].green = rand() % 256;
    pallet[i].blue = rand() % 256;
  }

  // generate pixels
  struct ppm_pixel* pixels = malloc (sizeof(struct ppm_pixel) * size * size);
  
  //mandlebrot
  struct timeval tstart, tend;
  double timer;
  gettimeofday(&tstart, NULL);
  for(int r = 0; r < size; r++) {
    for(int c = 0; c < size; c++) {
      float xfrac = (float) c / (float) size;
      float yfrac = (float) r / (float) size;
      float x_0 = xmin + xfrac * (xmax - xmin);
      float y_0 = ymin + yfrac * (ymax - ymin);

      float x = 0.0;
      float y = 0.0;
      int iteration = 0;

      while(iteration<maxIterations && x*x + y*y < 2*2) {
        float xtemp = x*x - y*y + x_0;
        y = 2*x*y + y_0;
        x = xtemp;
        iteration++;
      }
      //escaped
      if(iteration<maxIterations) {
        pixels[r * size + c] = pallet[iteration];
      }
      else{
        pixels[r * size + c].red = 0;
        pixels[r * size + c].green = 0;
        pixels[r * size + c].blue = 0;
      }
    }
  }
  gettimeofday(&tend, NULL);
  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  int timestamp = time(0);
  printf("Computed mandelbrot set (size=%dx%d) in %f seconds\n", size, size, timer);

  // write ppm
  char filename[256];
  sprintf(filename, "mandelbrot_%d_%d.ppm", size, timestamp);
  write_ppm(filename, pixels, size, size);
  free(pixels);
  free(pallet);

  return 0;

}

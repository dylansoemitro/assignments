#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"
#include<time.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: glitch <file.ppm>\n");
    return 0;
  }
  srand(time(0));
  // todo: your code here
  // read image
  int w;
  int h;
  struct ppm_pixel* image = read_ppm(argv[1], &w, &h);
  if (image == NULL) {
    printf("error reading file\n");
    return 0;
  }
  printf("Reading %s with width %d and height %d\n", argv[1], w, h);
  // glitch image
  for(int i = 0; i < w * h; i++) {
    image[i].red = image[i].red << (rand() % 4);
    image[i].green = image[i].green << (rand() % 4);
    image[i].blue = image[i].blue  << (rand() % 4);
  }
  // write image
  write_ppm("glitched.ppm", image, w, h);
  free(image);
  return 0;
}



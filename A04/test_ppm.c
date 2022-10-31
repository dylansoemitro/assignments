#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main() {
  // load feep-raw and print out the grid of pixels
  int w;
  int h;
  struct ppm_pixel* feep = read_ppm("feep-raw.ppm", &w, &h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("(%d %d %d) ", feep[i*w+j].red, feep[i*w+j].green, feep[i*w+j].blue);
    }
    printf("\n");
  }
  free(feep);
  return 0;
}


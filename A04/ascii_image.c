#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: ascii_image <file.ppm>\n");
    return 0;
  }
  int w;
  int h;
  struct ppm_pixel* image = read_ppm(argv[1], &w, &h);
  char *output = malloc(sizeof(char)*w*h);
  if (image == NULL) {
    printf("error reading file\n");
    return 0;
  }
  printf("Reading %s with width %d and height %d\n", argv[1], w, h);
  int intensity;
  for (int i = 0; i < w*h; i++) {
    intensity = (image[i].red + image[i].green + image[i].blue)/3;
    if (0<=intensity && intensity <=25){
      output[i] = '@';
    }
    else if (26<=intensity && intensity <=50){
      output[i] = '#';
    }
    else if (51<=intensity && intensity <=75){
      output[i] = '%';
    }
    else if (76<=intensity && intensity <=100){
      output[i] = '*';
    }
    else if (101<=intensity && intensity <=125){
      output[i] = 'o';
    }
    else if (126<=intensity && intensity <=150){
      output[i] = ';';
    }
    else if (151<=intensity && intensity <=175){
      output[i] = ':';
    }
    else if (176<=intensity && intensity <=200){
      output[i] = ',';
    }
    else if (201<=intensity && intensity <=225){
      output[i] = '.';
    }
    else if (226<=intensity && intensity <=255){
      output[i] = ' ';
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%c", output[i*w+j]);
    }
    printf("\n");
  }
  free(image);
  free(output);

  return 0;
}


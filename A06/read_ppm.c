#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// Choose *one* to implement
// struct ppm_pixel {
//     unsigned char red;
//     unsigned char green;
//     unsigned char blue;
// };


struct ppm_pixel* read_ppm(const char* filename, int* width, int* height) {
  FILE* infile = NULL;
  infile = fopen(filename, "r");
  if (infile == NULL) {
    printf("Error opening file. %s\n", filename);
    return NULL;
  }
  //scan through header
  char magic[128];
  fgets(magic, sizeof(magic),infile);
  if (strcmp(magic, "P6\n") != 0) {
    printf("Error: magic number is not P6.\n");
    exit(1);
  }
  char comments[128];
  
  while(fgets(comments, sizeof(comments),infile)[0] == '#') {
    continue;
  }
  //read width and height
  sscanf(comments, "%d %d", width, height);
  int maxval;
  fscanf(infile, "%d", &maxval);
  //skip last whitespace char
  fgets(comments, sizeof(comments),infile);
  //allocate memory for image
  struct ppm_pixel* image = malloc(*width * *height * sizeof(struct ppm_pixel));
  if (image == NULL) {
    printf("Error: memory allocation failed.");
    return NULL;
  }

  //read in image
  printf("Testing file %s : %d %d\n", filename, *width, *height);
  for(int i = 0; i < *width * *height; i++) {
    fread(&image[i].red, sizeof(unsigned char), 1, infile);
    fread(&image[i].green, sizeof(unsigned char), 1, infile);
    fread(&image[i].blue, sizeof(unsigned char), 1, infile);
  }
  fclose(infile);
  return image;


}

// struct ppm_pixel** read_ppm_2d(const char* filename, int* w, int* h) {
//   return NULL;
// }

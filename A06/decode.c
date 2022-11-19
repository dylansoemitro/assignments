#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: decode <file.ppm>\n");
    return 0;
  }

  int w;
  int h;
  unsigned char* image = (unsigned char*) read_ppm(argv[1], &w, &h);
  if (image == NULL) {
    printf("error reading file\n");
    return 0;
  }
  printf("Reading %s with width %d and height %d\n", argv[1], w, h);
  printf("Max number of characters in the image: %d\n", w * h * 3 / 8);

  char *message = malloc(w * h *3);
  for (int i = 0; i < w * h * 3; i++) {
    message[i] = (image[i] & 1) + '0';
  }
  //convert binary to ASCII
  char *decoded = malloc(w * h *3 / 8);
  for (int i = 0; i<w*h*3/8; i++){
    char *temp = malloc(8);
    for (int j = 0; j<8; j++){
      temp[j] = message[i*8+j];
    }
    decoded[i] = strtol(temp, NULL, 2);
    free(temp);
  }
  printf("Decoded message: %s", decoded);
  free(image);
  free(message);
  free(decoded);

  return 0;
}

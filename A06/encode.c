#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: encode <file.ppm>\n");
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
  char *message = malloc(w * h * 3 / 8);
  printf("Enter a message to encode: ");
  scanf ("%[^\n]%*c", message);
  //encode message into image
  //
  int messageLength = strlen(message);
  for (int i = 0; i < messageLength; i++) {
    //convert ASCII to binary
    char *temp = malloc(8);
    for (int j = 0; j < 8; j++) {
      temp[7-j] = (message[i] >> j) & 1;
    }
    //encode binary into image
    for (int j = 0; j < 8; j++) {
      image[i * 8 + j] = (image[i * 8 + j] & 254) | temp[j];
    }
    free(temp);
  }
  //write image to file
  int input_length = strlen(argv[1]);
  char input_name[50];
  strcpy(input_name, argv[1]);
  printf("input length: %d", input_length);
  char *filename = malloc(strlen(argv[1]) + 9);
  strncpy(filename, input_name+0, strlen(argv[1]) - 4);
  filename[strlen(argv[1]) - 4] = '\0';
  printf("\n filename: %s", filename);
  strcat(filename, "-encoded.ppm");
  printf("\n filename: %s", filename);
  write_ppm(filename, (struct ppm_pixel*) image, w, h);
  free(filename);
  free(image);
  free(message);
  return 0;
}


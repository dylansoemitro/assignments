#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned long img;
  scanf(" %lx", &img);
  printf("Image (unsigned long): %lx\n", img);

  // todo: your code here
  // output 8x8 1bpp sprite
  char output[8][8];

  unsigned long mask;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      mask = 0x1ul << (i*8+j);
      if(img & mask){
        output[i][j] = '@';
      }
      else{
        output[i][j] = ' ';
      }
  }
  }
 for(int i = 0; i < 8; i++){
   for(int j = 0; j < 8; j++){
     printf("%c", output[i][j]);
   }
   printf("\n");
 }
  return 0;
}
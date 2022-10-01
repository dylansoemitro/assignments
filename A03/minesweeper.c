#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void create_array(char *array, int m, int n, float p){
  for(int i = 0; i<m; i++){
    for(int j = 0; i<n; j++){
      int val = rand();
      if(val< (p*RAND_MAX)){
        array[i*n + j] = 'X';
      }
      else{
        array[i*n + j] = '.';
      }
    }
  }
}

int main(int argc, char *argv[]){
  srand(time(0));
  if (argc != 4) {
      printf("usage: %s m n p\n", argv[0]);
    }

  // char *a = argv[0];
  // char *b = argv[1];
  // char *c = argv[2];
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  float p = atof(argv[3]);

  char *two_d_array;
  two_d_array = malloc(sizeof(char)*(m*n));
  printf("%d %d %f\n", m, n, p);
  create_array(two_d_array, m, n, p);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // char out = ;
      //printf("(%d,%d) = ", i, j);
      printf("%c ", two_d_array[i*n + j]);
    }
    printf("\n");
  }
  free(two_d_array);
  two_d_array = NULL;
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void create_array(char *array, int m, int n, float p){
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
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

char check_surrounding(char* array, int m, int n, int i, int j){
  int count = 0;
  //array[i-1][j]
  if(i-1>=0 && array[(i-1)*n + j] == 'X'){
    count++;
  }
  //array[i+1][j]
  if(i+1<m && array[(i+1)*n + j] == 'X'){
    count++; 
  }
  //array[i][j-1]
  if(j-1>=0 && array[i*n + j-1] == 'X'){
    count++;
  }
  //array[i][j+1]
  if(j+1<n && array[i*n + j+1] == 'X'){
    count++;
  }
  //array[i-1][j-1]
  if(i-1>=0 && j-1>=0 && array[(i-1)*n + j-1] == 'X'){
    count++;
  }
  //array[i-1][j+1]
  if(i-1>=0 && j+1<n && array[(i-1)*n + j+1] == 'X'){
    count++;
  }
  //array[i+1][j-1]
  if(i+1<m && j-1>=0 && array[(i+1)*n + j-1] == 'X'){
    count++;
  }
  //array[i+1][j+1]
  if(i+1<m && j+1<n && array[(i+1)*n + j+1] == 'X'){
    count++;
  }
  //convert count to char
  return count + '0';
}

void print_array(char *array, int m, int n){
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      printf("%c ", array[i*n + j]);
    }
    printf("\n");
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
  print_array(two_d_array, m, n);
  printf("\n");
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      if(two_d_array[i*n + j] == '.'){
        two_d_array[i*n + j] = check_surrounding(two_d_array, m, n, i, j);
    }
    }
  }
  print_array(two_d_array, m, n);

  free(two_d_array);
  two_d_array = NULL;
  return 0;
}

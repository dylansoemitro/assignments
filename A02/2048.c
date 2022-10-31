#include <stdio.h>
#include <stdlib.h>
int main() {

  int shape = 4;


  // FILE* infile = NULL;
  // infile = fopen("input1.txt", "r");
  // if(infile == NULL){
  //   printf("Unable to locate file %s\n", "input.txt");
  //   exit(1);
  // }
  int matrix[4][4];
  // for(int i=0; i<shape; i++){
  //   for(int j=0; j<shape; j++){
  //     fscanf(infile, "%d ", &matrix[i][j]);
  //   }
  //   fscanf(infile,"\n");
  // }  
  for(int i=0; i<shape; i++){
    for(int j=0; j<shape; j++){
      scanf(" %d ", &matrix[i][j]);
    }
  }  

  //test print
  for(int i=0; i<shape; i++){
    for(int j=0; j<shape; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }  
  // fclose(infile);
  int maxShift = 0;
  int maxValue = 0;
  int curr;
  //loop through 2D array, checking if shift is possible
  for(int i=0; i<shape; i++){
    for(int j=0; j<shape; j++){
      if(matrix[i][j] > maxValue){
        maxValue = matrix[i][j];
      }
      curr = i; 
      while(curr>0){
        if(matrix[i][j] == matrix[curr-1][j] && 2*matrix[i][j] > maxShift){
            maxShift = 2*matrix[i][j];
            break;
        }
        else if (matrix[curr-1][j] != 0)
        {
          break;
        }
        else{
          curr -= 1;
        }
      }
      curr = i;
      while(curr<(shape-1)){
        if(matrix[i][j] == matrix[curr+1][j] && 2*matrix[i][j] > maxShift){
            maxShift = 2*matrix[i][j];
            break;
        }
        else if (matrix[curr+1][j] != 0)
        {
          break;
        }
        else{
          curr += 1;
        }
      }
      curr = j;
      while(curr>0){
        if(matrix[i][j] == matrix[i][curr-1] && 2*matrix[i][j] > maxShift){
            maxShift = 2*matrix[i][j];
            break;
        }
        else if (matrix[i][curr-1] != 0)
        {
          break;
        }
        else{
          curr -= 1;
        }
      }
      curr = j;
      while(curr<(shape-1)){
        if(matrix[i][j] == matrix[i][curr+1] && 2*matrix[i][j] > maxShift){
            maxShift = 2*matrix[i][j];
            break;
        }
        else if (matrix[i][curr+1] != 0 )
        {
          break;
        }
        
        else{
          curr += 1;
        }
    }
  }
  }
  if(maxShift == 0){
    maxShift = maxValue;
  }
  printf("The largest value is %d. \n", maxShift);

  return 0;
}

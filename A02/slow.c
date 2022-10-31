#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert phrase into ent-phrase
void convert(char* phrase, int len, int pause_length, char* ent_phrase){
  for(int i = 0; i<len+len*pause_length; i++){ //inserts pause as .
    if(i % (pause_length+1) == 0){
      ent_phrase[i] = phrase[(i/(pause_length+1))];
    }
    else{
      ent_phrase[i] = '.';
    }
  }
  ent_phrase[len+len*pause_length] = '\0'; //terminating char
}
int main() {


  char phrase[32];
  printf("Text: ");
  scanf("%s", phrase);
  int pause_length;
  printf("Pause length: ");
  scanf("%d", &pause_length);
  int len = strlen(phrase);
  char* ent_phrase = malloc(len+len*pause_length+1); //accounts for size + terminating char
  convert(phrase, len, pause_length, ent_phrase);
  printf("%s\n", ent_phrase);
  free(ent_phrase);
  ent_phrase = NULL;
  return 0;
}

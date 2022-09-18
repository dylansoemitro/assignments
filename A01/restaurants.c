
#include <stdio.h>
#include <string.h>

struct restaurant{
  char name[64];
  int openHour;
  int closeHour;
  float stars;
}
int main() {
  

  char word[1024];
 

  printf("Enter a word: ");
  scanf("%s", word);
  int shift;
  printf("Enter a cypher: ");
  scanf("%d", &shift);
  
  int len = strlen(word);
  //loop through the string
  for (int i = 0; i < len; i++) {
    int ascii = word[i];
    //use ascii modulation 'a'=97
    int encrypted = (shift+ascii-97)%26+97;
    //check if negative shift results in ascii code before a,
    //meaning that we need to loop back around the alphabet
    if(encrypted<97){
       word[i] = encrypted+26;
    }
    else{
      word[i] = encrypted;
    }
  }
   printf("Your cypher is %s \n", word);
  return 0;
}
  22   vbv
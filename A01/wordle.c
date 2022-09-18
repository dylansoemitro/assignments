#include <stdio.h>
#include <string.h>
#include <time.h>
#include "words.h" // header that defined chooseWord()

int wordCheck(const char* input, const char* reference){
  if(strcmp(input, reference) == 0){
    printf("You guessed the right word!\n");
    return 1;
  }
  else{
    for(int i=0; i<5; i++){
      char curr = input[i];
      //flags to check if current char in right position or in string
      int inStringFlag = 0;
      int correctPosFlag = 0;
      for(int j=0; j<5; j++){
        if(curr == reference[j] && i == j){ //correct position
          correctPosFlag = 1;
          break;
        }
        else if (curr == reference[j])//in string but not correct position
        {
          inStringFlag = 1;
        }
      }
      if (correctPosFlag == 1){
        printf("%c is in the word and in the correct spot!\n", curr);
      }
      else if (inStringFlag == 1){
        printf("%c is in the word (but not in the correct spot)!\n", curr);
      }
      else{
        printf("%c is NOT in the word.\n", curr);
      }
    }
    return 0;
  }
}
int main() {
  srand(time(0));
  const char* word = chooseWord();
  printf("cheat: %s\n", word);

  char input[5];
  int correctFlag = 0;//flag to see if user guessed the word correctly
  //user has 6 tries
  for(int z=0; z<6; z++){
    printf("Please enter a 5-letter word: ");
    scanf("%s", input);
    int isCorrect = wordCheck(input, word);
    //if user input matches reference word, break out of loop.
    if(isCorrect==1){
      correctFlag = 1;
      break;
    }
  }
  //if user didn't guess correctly, output correct word
  if (correctFlag == 0){
    printf("Sorry, you ran out of tries. The word is %s\n", word);
  }
  return 0;
}

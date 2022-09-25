#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct restaurant{
  char name[64];
  int openHour;
  int closeHour;
  float stars;
};



int main() {

  

  // strcpy(restaurant_arr[0].name, "Sushi Atsumi");
  // restaurant_arr[0].openHour = 11;
  // restaurant_arr[0].closeHour = 23;
  // restaurant_arr[0].stars = 3.5;

  // strcpy(restaurant_arr[1].name, "The Thirsty Horse");
  // restaurant_arr[1].openHour = 17;
  // restaurant_arr[1].closeHour = 2;
  // restaurant_arr[1].stars = 4.5;

  // strcpy(restaurant_arr[2].name, "Magic Bean Coffee");
  // restaurant_arr[2].openHour = 6;
  // restaurant_arr[2].closeHour = 15;
  // restaurant_arr[2].stars = 4.1;
  
  int size;
  printf("Enter a number of restaurants: ");
  scanf("%d", &size);
  struct restaurant *restaurant_arr;
  //create a dynamic array corresponding to size input of restaurant struct
  restaurant_arr =  malloc(size*sizeof(struct restaurant));
  for (int i = 0; i<size; i++){
    char restaurantName[30];
    int openHour, closeHour;
    float stars;
    printf("Enter a name: ");
    scanf(" %[^\n]%*c", restaurantName);\
    strcpy(restaurant_arr[i].name, restaurantName);
    printf("Open time: ");
    scanf(" %d%*c", &openHour);
    restaurant_arr[i].openHour = openHour;
    printf("Close time: ");
    scanf(" %d%*c", &closeHour);
    restaurant_arr[i].closeHour = closeHour;
    printf("Stars: ");
    scanf(" %f%*c", &stars);
    restaurant_arr[i].stars = stars;
  }
  printf("Welcome to Dynamic Donna's Restaurant Directory\n");
  for (int i = 0; i < size; i++) {
    printf("%d) %s open: %02d:00 close: %02d:00 stars: %0.1f\n", i, restaurant_arr[i].name, restaurant_arr[i].openHour, restaurant_arr[i].closeHour, restaurant_arr[i].stars);
  }

  free(restaurant_arr);
  restaurant_arr = NULL;
  return 0;
}

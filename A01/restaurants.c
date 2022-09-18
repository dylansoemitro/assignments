
#include <stdio.h>
#include <string.h>

struct restaurant{
  char name[64];
  int openHour;
  int closeHour;
  float stars;
};

int main() {

  struct restaurant restaurant_arr[3];
  //struct restaurant restaurant1, restaurant2, restaurant3;

  strcpy(restaurant_arr[0].name, "Sushi Atsumi");
  restaurant_arr[0].openHour = 11;
  restaurant_arr[0].closeHour = 23;
  restaurant_arr[0].stars = 3.5;

  strcpy(restaurant_arr[1].name, "The Thirsty Horse");
  restaurant_arr[1].openHour = 17;
  restaurant_arr[1].closeHour = 2;
  restaurant_arr[1].stars = 4.5;

  strcpy(restaurant_arr[2].name, "Magic Bean Coffee");
  restaurant_arr[2].openHour = 6;
  restaurant_arr[2].closeHour = 15;
  restaurant_arr[2].stars = 4.1;
  int hour;
  printf("Welcome to Steven Struct's Restaurant List. \nWhat hour is it (24 hour clock)?  ");
  scanf("%d", &hour);
  

  //loop through the string
  for (int i = 0; i < 3; i++) {
    printf("%d) %s open: %02d:00 close: %02d:00 stars: %0.1f\n", i, restaurant_arr[i].name, restaurant_arr[i].openHour, restaurant_arr[i].closeHour, restaurant_arr[i].stars);
  }

  int restaurantToVisit;
  printf("What restaurant do you want to visit ? [0,1,2] ");
  scanf("%d", &restaurantToVisit);

  if (hour == restaurant_arr[restaurantToVisit].closeHour){
     printf("Sorry, %s is closing!", restaurant_arr[restaurantToVisit].name);
  }
  else if (restaurant_arr[restaurantToVisit].closeHour > restaurant_arr[restaurantToVisit].openHour){
      if(hour < restaurant_arr[restaurantToVisit].closeHour && hour > restaurant_arr[restaurantToVisit].openHour){
        printf("Excellent choice. %s will be open for %d more hours.\n", restaurant_arr[restaurantToVisit].name, restaurant_arr[restaurantToVisit].closeHour-hour);
      }
      else if(hour > restaurant_arr[restaurantToVisit].closeHour){
        printf("%s is closed at %d o'clock!!\n", restaurant_arr[restaurantToVisit].name, restaurant_arr[restaurantToVisit].closeHour);
      }
      else{        
        printf("%s isn't open until %d o'clock!!\n", restaurant_arr[restaurantToVisit].name, restaurant_arr[restaurantToVisit].openHour);
      }
  }
  else{
    if(hour<24 && hour>restaurant_arr[restaurantToVisit].openHour){
      printf("Excellent choice. %s will be open for %d more hours.\n", restaurant_arr[restaurantToVisit].name, 24-hour);
    } 
    else if(hour<restaurant_arr[restaurantToVisit].closeHour){
      printf("Excellent choice. %s will be open for %d more hours.\n", restaurant_arr[restaurantToVisit].name, restaurant_arr[restaurantToVisit].closeHour-hour);
    }
    else if(hour > restaurant_arr[restaurantToVisit].closeHour){
      printf("%s is closed at %d o'clock!!\n", restaurant_arr[restaurantToVisit].name, restaurant_arr[restaurantToVisit].closeHour);
    }
    else{
      printf("%s isn't open until %d o'clock!!\n", restaurant_arr[restaurantToVisit].name, restaurant_arr[restaurantToVisit].openHour);

    }
  }

  
  return 0;
}

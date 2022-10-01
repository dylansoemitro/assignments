#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct restaurant{
  char name[64];
  int openHour;
  int closeHour;
  float stars;
};

struct node{
  struct restaurant restaurant_vars;
  struct node *next;
};

// struct node* insert_sorted(struct node *head, struct restaurant *restaurant_vars){
//   struct node *node = malloc(sizeof(struct node));
//   node->restaurant_vars = restaurant_vars;
//   node->next = NULL;
//   if (head == NULL){
//     return node;
//   }
//   if (head->restaurant_vars->stars < restaurant_vars->stars){
//     node->next = head;
//     return node;
//   }
//   struct node *curr = head;
//   while (curr->next != NULL && curr->next->restaurant_vars->stars > restaurant_vars->stars){
//     curr = curr->next;
//   }
//   node->next = curr->next;
//   curr->next = node;
//   return head;
// }

struct node* insert_sorted(struct node *head, struct restaurant restaurant_vars){
  struct node *n = malloc(sizeof(struct node));
  n->restaurant_vars = restaurant_vars;
  n->next = NULL;
  if (head == NULL){
    return n;
  }
  if (head->restaurant_vars.stars < restaurant_vars.stars){
    n->next = head;
    return n;
  }
  struct node *curr = head;
  while (curr->next != NULL && curr->next->restaurant_vars.stars > restaurant_vars.stars){
    curr = curr->next;
  }
  n->next = curr->next;
  curr->next = n;
  return head;
}
// struct node* insert_sorted(struct node *head, struct restaurant restaurant_vars){
//   //initialize node
//   struct node *n = malloc(sizeof(struct node));
//   n->restaurant_vars = restaurant_vars;
//   n->next = NULL;
//   //if head is null, return node
//   if (head == NULL){
//     return n;
//   }
//   printf("%f\n",restaurant_vars.stars);
//   //if head is less than node, insert node at head
//   if (head->restaurant_vars->stars < restaurant_vars.stars){
//     n->next = head;
//     return n;
//   }
//   struct node *curr = head;
//   //iterate to find right spot to insert node
//   while (curr->next != NULL && curr->next->restaurant_vars->stars > restaurant_vars.stars){
//     curr = curr->next;
//   }
//   n->next = curr->next;
//   curr->next = n;
//   return head;
// }
void clear(struct node *head){
  struct node *curr = head;
  while (curr != NULL){
    struct node *temp = curr;
    curr = curr->next;
    free(temp);
  }
}

void print(struct node *head){
  struct node *curr = head;
  int counter = 1;
  while (curr != NULL){
    printf("%d) %s open: %02d:00 close: %02d:00 stars: %0.1f\n",
    counter, curr->restaurant_vars.name, curr->restaurant_vars.openHour, 
    curr->restaurant_vars.closeHour, curr->restaurant_vars.stars);
    curr = curr->next;
    counter++;
    }
  
}

int main() {
  int size;
  printf("Enter a number of restaurants: ");
  scanf("%d", &size);
  struct restaurant curr_restaurant; 
  struct node *head = NULL;
  for (int i = 0; i<size; i++){
    
    char restaurantName[30];
    int openHour, closeHour;
    float stars;
    printf("Enter a name: ");
    scanf(" %[^\n]%*c", restaurantName);
    strcpy(curr_restaurant.name, restaurantName);
    printf("Open time: ");
    scanf(" %d%*c", &openHour);
    curr_restaurant.openHour = openHour;
    printf("Close time: ");
    scanf(" %d%*c", &closeHour);
    curr_restaurant.closeHour = closeHour;
    printf("Stars: ");
    scanf(" %f%*c", &stars);
    curr_restaurant.stars = stars;
    head = insert_sorted(head, curr_restaurant);
    printf("done\n");
  }
  printf("Welcome to Sorted Sally's Restaurant Directory. \n");
  //print the list
  print(head);
  clear(head);
  head = NULL;
  return 0;
}

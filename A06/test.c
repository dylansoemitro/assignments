#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(){
    char message[100];
    printf("Enter a message to encode: ");
    scanf ("%[^\n]%*c", message);
    printf("Message to encode: %s", message);
    char this = (message[1] >> 3) & 1;
    printf("this: %d", this);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 256

int main ( int argc, char *argv[] ) {
    char buffer[MAX_BUFFER];
    int age;

    printf("Name >> ");
    scanf("%s", buffer);
    printf("Age >> ");
    scanf("%d", &age);

    fprintf(stdout, "Hello %s (%d)\n", buffer, age);
    
    return EXIT_SUCCESS;
}
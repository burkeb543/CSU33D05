#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("How many elements: ");
  int num_elements;
  scanf("%d", &num_elements);
  int* numbers = NULL;
  numbers = (int*)malloc(sizeof(int) * num_elements);
  int sum_of_elements = 0;
  for (int i = 0; i < num_elements; i++){
    printf("Enter number %d: ",i+1);
    scanf("%d", &numbers[i]);
    sum_of_elements += numbers[i];
  }

  printf("Sum of elements: %d", sum_of_elements);
  
  return 0;
}
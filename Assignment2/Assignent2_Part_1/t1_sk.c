#include <stdio.h>
#include <stdlib.h>
#include "t1.h"


//Fills the array with ascending, consecutive numbers, starting from 0.
void fill_ascending(int *array, int size)
{
    //TODO
    for (int i = 0; i < size; i++){
        array[i] = i;
    }

}
//Fills the array with descending numbers, starting from size-1
void fill_descending(int *array, int size)
{
    //TODO
    int n = 0;
    for (int i = size - 1; i > -1; i--){
        array[i] = n;
        n++;
    }
}

//Fills the array with uniform numbers.
void fill_uniform(int *array, int size)
{
    //TODO
    for (int i = 0; i < size; i++){
        array[i] = 3;
    }

}

//Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
void fill_with_duplicates(int *array, int size)
{
    //TODO
    for (int i = 0; i < size; i++){
        int randNum = rand() % size; // returns random number in a given range
        array[i] = randNum;
    }

}


//Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int *array, int size)
{
    //TODO
    array[0] = rand() % size; // returns random number in a given range
    int same = 0; // 1 if the latest generated random number is the same as any of the previously genereted numbers, 0 otherwise

    for (int i = 1; i < size; i++){
            same = 0;
        int randNum = rand() % size; // Generate random number
        for (int j = 0; j < i; j++){
            if (randNum == array[j]) // Check if new random number is the same as any of the previous random numbers
                same = 1;
        }
        if (same == 0){ // If random number is new, assign the current array element with the random number
            array[i] = randNum;
        }
        else{
            i--; // Repeat the process for this array element if the random number wasn't original
        }

    }

}

void printArray(int* arr, int size){
  int i;
  for(i=0; i<size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}
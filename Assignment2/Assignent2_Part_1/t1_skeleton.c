#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
        array[i] = randNum; // sets array element with the number
    }

}


//Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int *array, int size)
{
    //TODO
    array[0] = rand() % size; // sets first element in the array to a random number in the given range
    bool match = false; // becomes true if the latest generated random number is the same as any of the previous array eleents

    int i = 1; // current index of the array being filled

    while( i < size ){ // continue looping until all array elements are filled
      int randNum = rand() % size; // generates a random number in the given range
      for (int j = 0; j < i; j++){
            if (randNum == array[j]) // check if the new random number matches any of the array elements
                match = true; // if a match is found set to true
        }
        if (match == false){ // random number generated is new
          array[i] = randNum; // fill current array element with the random number
          i++; // next array element to be filled
        }
        match = false; // reset to start for next element
    }

}

void printArray(int* arr, int size){
  int i;
  for(i=0; i<size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}
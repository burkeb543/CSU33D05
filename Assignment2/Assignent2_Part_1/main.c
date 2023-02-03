#include "t1.h"
#include "t1_skeleton.c"
#include <stdio.h>



int main()
{
    //TODO test your functions here
    int size = 20;
    int array[size];
    int *arrayPtr = array;

    fill_ascending(arrayPtr, size);
    printArray(arrayPtr, size);
    fill_descending(arrayPtr, size);
    printArray(arrayPtr, size);
    fill_uniform(arrayPtr, size);
    printArray(arrayPtr, size);

    fill_with_duplicates(arrayPtr, size);
    printArray(arrayPtr, size);

    fill_without_duplicates(arrayPtr, size);
    printArray(arrayPtr, size);



}

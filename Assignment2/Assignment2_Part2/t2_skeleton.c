#include <stdio.h>

int number_comparisons = 0;
int number_swaps = 0;


// swap function to swap numbers in the array
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    number_swaps++;
}


void selectionSort(int arr[], int size)
{
  //TODO
  int i, j, min_num;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < size - 1; i++)
  {
        // Find the minimum element in unsorted array
      min_num = i;
      for (j = i + 1; j < size; j++){
        number_comparisons++;
        if (arr[j] < arr[min_num])
            min_num = j;
      }

        // Function to swap the minimum number with the first number in the array
        swap(&arr[min_num], &arr[i]);
  }
}


void insertionSort(int arr[], int size)
{
  //TODO
  int i, j, key;
  for (i = 1; i < size; i++) { //loop through array starting at array's second index
        number_comparisons++;
        key = arr[i];
        j = i - 1;

        // move array elements greater than the key down one position in the array
        while (j > -1 && arr[j] > key) {
            arr[j + 1] = arr[j];
            number_swaps++;
            number_comparisons++;
            j = j - 1;
        }
        arr[j + 1] = key;
  }

}

void quick_Sort(int arr[], int low, int high)
{
    number_comparisons++;
    if (low < high)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1); // index of smaller element and indicates the right position of pivot found so far

        for (int j = low; j <= high - 1; j++) //
        {
            number_comparisons++;
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int partition_index = i + 1;

        /*sort the numbers before
        partition and after partition separately*/
        quick_Sort(arr, low, partition_index - 1);
        quick_Sort(arr, partition_index + 1, high);
    }
}


void quickSort(int arr[], int size)
{
    //TODO
    quick_Sort(arr, 0, size - 1);

}
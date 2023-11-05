// Shiva Khatri
// Programming Assignment #3

/**
This C program showcases the use of pointers in sorting and array manipulation. 
it has total of 5 functions including the main function. 
It includes a set of functions for copying, sorting, and outputting integer arrays. 
The `copy` function duplicates the contents of one array into another using pointers.
 Two sorting functions, `sort1` and `sort2`, implement bubble sort and selection sort,
  respectively, with pointer-based array traversal and comparisons. The `output` function 
  employs pointers to print array elements. The `main` function demonstrates these functions 
  by sorting and printing two arrays, illustrating the power of pointers in C programming 
  for efficient array operations. Starting with a reversed list of numbers, the program displays
   the sorted results for both sorting methods, emphasizing the role of pointers in array
    manipulation and sorting algorithms.
*/

#include <stdio.h> // include the standard input output library

void copy(int *array1, int *array2, int size) { // copy function to copy the elements of the array1 to array2 which takes array1, array2 and size of the array as an integer
    int *p = array1;  // pointer to the first element of the array1 by assigning the address of the first element to the pointer
    int *q = array2;  // pointer to the first element of the array2 by assigning the address of the first element to the pointer
    for ( ; p< array1 + size; p++, q++) { // loop to copy the array1 elements to array2 by incrementing the pointer
        *q = *p; // copy the value of the pointer which is the value of the array1 element to the pointer which is the value of the array2 element
    }
} // end of the copy function

// Function to perform the bubble sort
void sort1(int *arr, int size) { // sort function to sort the elements of the array which takes array as a pointer and size of the array as an integer
    int sorted = 0; // variable to check if the array is sorted which is initialized to 0
    int k = size;   // variable to store the size of the array
    int temp;   // variable to store the temporary value
    int *p;   // pointer to the first element of the array by assigning the address of the first element to the pointer

    while (!sorted) { // loop to check if the array is sorted
        sorted = 1;  // set the sorted variable to 1 to break the loop if the array is sorted
        p = arr; // set the pointer to the first element of the array
        for (; p < arr + k - 1; p++) { // loop to sort the array elements by incrementing the pointer and decrementing the size of the array
            if (*p > *(p + 1)) { // check if the current element is greater than the next element
                // Swap elements if they are in the wrong order
                temp = *p;  // store the value of the current element to the temporary variable
                *p = *(p + 1); // store the value of the next element to the current element
                *(p + 1) = temp; // store the value of the temporary variable to the next element
                sorted = 0; // set the sorted variable to 0 to continue the loop
            } // end of the if statement
        }
        k--; // decrement the size of the array
    }
}

// Function to perform the selection sort
void sort2(int *arr, int size) { // sort function to sort the elements of the array which takes array as a pointer and size of the array as an integer
     int *p; // pointer to the first element of the array by assigning the address of the first element to the pointer
    int *q;  // pointer to the first element of the array by assigning the address of the first element to the pointer
    int minPosition; // variable to store the position of the minimum element
    int temp; // variable to store the temporary value

    p = arr; // set the pointer to the first element of the array
    for (; p < arr + size - 1; p++) { // loop to sort the array elements by incrementing the pointer and decrementing the size of the array
        minPosition = p - arr; // set the minimum position to the current position
        q = p + 1; // set the pointer to the next element of the array
        for (; q < arr + size; q++) { // loop to find the minimum element by incrementing the pointer
            if (*q < *(arr + minPosition)) { // check if the current element is less than the minimum element
                minPosition = q - arr; // set the minimum position to the current position
            }
        }
        temp = *(arr + minPosition); // store the value of the minimum element to the temporary variable
        *(arr + minPosition) = *p; // store the value of the current element to the minimum element
        *p = temp; // store the value of the temporary variable to the current element
    } // end of the for loop
} // end of the sort function


void output(int *array, int size) { // output function to print the array which takes array as a pointer and size of the array as an integer
    int *p = array;  // pointer to the first element of the array by assigning the address of the first element to the pointer
    for ( ; p< array + size ; p++) { // loop to print the array elements by incrementing the pointer
        printf("%d ", *(p));  // print the value of the pointer which is the value of the array element
    }
    printf("\n"); // print new line
} // end of the output function

int main() { // main function
    int array1[]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1} ; // array1 to store the elements of the array
    int array2[10]; // array2 to store the elements of the array
    int size=10; // variable to store the size of the array
    copy(array1, array2, size); // call the copy function to copy the elements of the array1 to array2
    sort1(array1, size); // call the sort1 function to sort the elements of the array1 which takes array1 and size of the array as an integer
    output(array1, size); // call the output function to print the array1 which takes array1 and size of the array as an integer
    sort2(array2, size); // call the sort2 function to sort the elements of the array2 which takes array2 and size of the array as an integer
    output(array2, size); // call the output function to print the array2 which takes array2 and size of the array as an integer

    return 0; // return 0 to end the program
} // end of the main function



// Output

/**
  1 2 3 4 5 6 7 8 9 10 
  1 2 3 4 5 6 7 8 9 10 
*/
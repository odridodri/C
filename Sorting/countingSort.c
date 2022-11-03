/*Write a program to implement counting sort in C. Some considerations/choices:
On what type of data would you like your program to work? (Integers should be fine but you could try doubles or strings.)
How would you like to store the array of items to be sorted? How about the other arrays needed to execute the algorithm? 
How would you like to initialize the array of values to sort? (Read data from a file, generate random numbers, populate with a preset list?)
What functionality might you like to add to verify your results (e.g., functions to print intermediate results?)?
Make sure your program will work with lists that have duplicate values. */
#include <stdio.h>
#define SIZE 6

void printArr(int* arr, int x);
void countingSort(int * input, int * output);

int main() {

    int input[SIZE] = {7, 5, 8, 2, 9, 9};
    int output[SIZE];

    printf("Initial Array: ");
    printArr(input, SIZE);
    
    countingSort(input, output);

    printf("Final Array: ");
    printArr(output, SIZE);
}

void printArr(int* arr, int x) {
    for (int i = 0; i < x; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int * input, int * output) {
    int m;
    int k = 10;
    int C[k];

    for (int i = 0; i < k; i++) {C[i] = 0;}
    //printArr(C, k);
    //Initialize C array.
    for (int j = 0; j < SIZE; j++) {C[input[j]]++;}
    //printArr(C, k);
    // C[i] is no. of times i appears in A[]
    for (int i = 1; i < k; i++) {C[i] = C[i]+C[i-1];}
        //printArr(C, k);}
    printf("Final C Array: ");
    printArr(C, k);
    //C[i] now has #items with value <= i
    for (int j=SIZE-1; j>=0; j--) {
        m = C[input[j]];
        output[m-1] = input[j];
        C[input[j]]--;
        //printArr(C, k);
    }
}
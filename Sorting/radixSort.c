#include <stdio.h>

void printArr(int* arr, int x);
int maxNum(int * arr, int n);
void countingSort(int * input, int size, int spot);

int main() {
    int NDIGITS= 2; //currently hardcoded

    //every number same no. of digits for now
    int input[] = {71, 563, 852, 23, 91, 98};

    printf("Initial Array: ");
    
    //no need to hardcode SIZE 
    int size = sizeof(input)/sizeof(input[0]);
    printArr(input, size);
    //get maximuim number so we can make C according to that
    int max = maxNum(input, size);

    for (int i = 1; max/i > 0; i*=10) { 
        //until max is no longer divides to an integer, then we know its the end
        //when divide by i, it is the number in x place going from back to front
        countingSort(input, size, i);
        printf("Post Counting Sort Iteration: ");
        printArr(input, size);
    }
    
    printf("Final Array: ");
    printArr(input, size);
}

void printArr(int* arr, int x) {
    for (int i = 0; i < x; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maxNum(int * arr, int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) { max = arr[i]; }
  }
  return max;
}

void countingSort(int * input, int size, int spot) {
    int m, n;
    int output[size + 1];
    int max = (input[0]/spot)%10;

    for (int i = 1; i < size; i++) {
        if (((input[i] / spot) % 10) > max) {
            max = input[i];
        }
    }
    int C[max + 1];

    for (int i = 0; i < max; i++) {C[i] = 0;}
    //printArr(C, k);
    //Initialize C array.
    for (int j = 0; j < size; j++) {
        n = (input[j]/spot)%10;
        C[n]++;
        }
    //printArr(C, k);
    // C[i] is no. of times i appears in A[]
    for (int i = 1; i < 10; i++) {C[i] = C[i]+C[i-1];}
        //printArr(C, k);}
    //printf("Final C Array: ");
    //printArr(C, max);
    //C[i] now has #items with value <= i
    for (int j=size-1; j>=0; j--) {
        n = (input[j]/spot)%10;
        m = C[n];
        output[m-1] = input[j];
        C[n]--;
        //printArr(C, k);
    }

    for (int i = 0; i < size; i++) {
        input[i] = output[i];
    }
}

#include <stdio.h>
#define SIZE 5

//HEADERS
//sorting functions
int *insertionSort(int * arr);
int *bubbleSort(int * arr);
int *selectionSort(int * arr);
int *gnomeSort(int * arr);

//helper functions
int * replicate(int * arr, int * to);
void print(int * arr);

//MAIN
void main() {
    int arr[SIZE] = {8, 3, 7, 4, 1};
    int arr2[SIZE];
    int arr3[SIZE] = {2, 5, 3, 1, 4};
    int arr4[SIZE];

    printf("Original array: ");
    print(arr);

    replicate(arr, arr2);
    replicate(arr3, arr4);

    insertionSort(arr);
    bubbleSort(arr2);
    selectionSort(arr3);
    gnomeSort(arr4);
};

//SORTING IMPLEMENTATIONS
//insertion sort implementation, returns 1 when done
int *insertionSort(int * arr) {
    //int N = sizeof arr;
    printf("Results of Insertion Sort:\n");
    int j = 0;
    for (int i = 1; i < SIZE; i++) { //make limit as tight-- start with i = 1, save one iteration
        int key = arr[i];
        for (j = i-1; j>=0 && arr[j]>key; j--) {
            arr[j+1] = arr[j];
//            printf("It %d: ", i);
//           print(arr);
        }
        arr[j+1] = key;
        printf("Results of this iteration: ");
        print(arr);
    }

    printf("Final Array after insertion sort: ");
    print(arr);
    printf("\n");
    return arr;
};

//bubblesort implementation, returns 1 when done
int *bubbleSort(int * arr) {
    //int N = sizeof arr;
    printf("Results of Bubble Sort:\n");
    int temp = 0;
    int flag = 0;
    int id = 1;
    while(flag < SIZE-1) {
        flag = 0;
        for (int i = 1; i < SIZE; i++) {
            if (arr[i] < arr[i-1]) {
                temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            } else {
                flag++;
                //if no change, flag + 1
            }
            printf("It %d: ", id);
            print(arr);
        }
        printf("Final Array for this iteration: ");
        print(arr);
        id++;
        //does an extra pass 
    }
    printf("Final Array after bubble sort: ");
    print(arr);
    printf("\n");
    return arr;
};

//selection sort implementation
int * selectionSort(int * arr) {
    printf("Results of Selection Sort:\n");
    for (int i = 0; i < SIZE-1; i++) {
        int temp = arr[i]; //2
        int temp_id = i;
        //iterate through side to find
        for (int j=i+1; j < SIZE; j++){
            if (arr[j]<temp) {
                temp = arr[j];
                temp_id= j;
            }
        }

        if (temp != arr[i]) {
            arr[temp_id] = arr[i];
            arr[i] = temp;
        }

        printf("Final Array for this iteration: ");
        print(arr);
    }

    printf("Final Array after selection sort: ");
    print(arr);
    printf("\n");
    return arr;
}

//gnome sort implementation
int *gnomeSort(int * arr) {
    printf("Results of Gnome Sort:\n");
    int temp;
    for (int i=0; i < SIZE-1; i++) {
        printf("Index: %d\n", i);
        if (arr[i]>arr[i+1]) {
            //if previous is greater, than swap
            temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
            if (i >= 1) {
                i=i-2;
            };
            printf("Swap Occured: ");
            print(arr);
        };
    }

    printf("Final Array after gnome sort: ");
    print(arr);
    printf("\n");

    return arr;
}

//HELPER FUNCTIONS
//replicates first array to second array
int * replicate(int * arr, int * to) {
    for (int i = 0; i < SIZE; i++) {
        to[i] = arr[i];
    }
    return to;
}
//prints content of each array
void print(int * arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

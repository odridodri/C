#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//declare struct
struct item {
    double value;
    struct item * next;
};

//declare functions
struct item * initialize();
void Insert(struct item *listhead, double value);
void printBuckets(struct item *list);
void Initialize(struct item ** buckets);
void insertionsort(struct item * head);
int Length(struct item *listhead);

//global var
struct item* sorted;

//main
int main(int argc, char *argv[]) {
    double nums[SIZE] = {0.72, 0.17, 0.39, 0.26, 0.78, 0.94, 0.21, 0.12, 0.23, 0.68};

    if (argc < 2 || atoi(argv[1]) <1 || atoi(argv[1]) > 1000) {
		printf("Usage: %s Positive integer\n",argv[0]);
		return 0;
	}

	int N = atoi(argv[1]);

    //make N 10

    //CREATE N BUCKETS
    struct item **buckets;
    buckets = (struct item **)malloc(sizeof(struct item *) * SIZE);
    Initialize(buckets);

    //CREATE INTERVALS
    double upper[N];
    double lower[N];

    lower[0] = 0;
    for (int j = 1; j < N; j++){
        upper[j-1] = 1.0/N*j;
        lower[j] = upper[j-1];
    }
    upper[N-1] = 1;

    //distribute list into buckets
    for (int i = 0; i < SIZE; i++) {
        //looping through nums

        //then loop through intervals
        for (int j = 0; j < SIZE; j++) {
            
        //printf("Upper; %f, Lower: %f\n", upper[j], lower[j]);
            //if in the interval, add value to bucket
            if (nums[i] >= lower[j] && nums[i] < upper[j]) {
                //then add to bucket
                //printf("inside if, nums: %f\n, j:%d\n", nums[i], j);
                Insert(buckets[j], nums[i]);
                break;
            }
        }
    }

    struct item * temp;
    temp = buckets[0];

    printf("Buckets: \n");
    for (int i = 0; i < N; i++) {
        temp = buckets[i]->next;
        printf("Bucket[%d]: ", i);
        printBuckets(temp);
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        if (buckets[i]->next != NULL) {
            insertionsort(buckets[i]->next);
        }
    }

    printf("New Buckets: \n");
    for (int i = 0; i < N; i++) {
        temp = buckets[i]->next;
        printf("Bucket[%d]: ", i);
        printBuckets(temp);
        printf("\n");
    }
    printf("\n");

    
    printf("Sorted List: ");
    for (int i = 0; i < N; i++) {
        temp = buckets[i]->next;
        printBuckets(temp);
    }
    printf("\n");

    return 0;
}

//insert value to linkedlist of items for each bucket
void Insert(struct item *listhead, double value) {

    struct item * temp; //temporary temp
    temp = listhead;

    while (temp->next != NULL) {
        temp = temp->next; //find the last next so we can connect to new node
    }

    //create new node
    //put pointer to next one so 
    temp->next = initialize();
    temp->next->value = value; //assign value since default is -1
}

struct item * initialize() {
    struct item * ptr = malloc(sizeof(struct item)); //Creating Head
    if (ptr == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }
    
    ptr->value = -1; //Make -1 to indicate empty value
    ptr->next = NULL; //Initially has no next door neighbor
    return ptr;
};

void printBuckets(struct item *list) {
  struct item *cur = list;
  while (cur) {
    printf("%.2f ", cur->value);
    cur = cur->next;
  }
}

void Initialize(struct item ** buckets) {
    //Initialize and give memory to each spot in buckets
    //Give each buckets spot a vertex pointer
    for (int i = 0; i < 1000 ;i++) {
        struct item * p = malloc(sizeof(struct item));
        if (p==NULL) {
            printf("Memory allocation failed.");
            return;
        }
        buckets[i] = p;
    }
    
};
  
// function to sort a singly linked list 
// using insertion sort
void insertionsort(struct item * head)
{
    struct item* current = head; //0.17
    int len = Length(current);

    for (int i=0; i<len-1; i++) {
        struct item* current = head; //0.17
        for (int i=0; i<len-1; i++) {
            //printf("%f, %f\n", current->value, current->next->value);
            if (current->value > current->next->value) {
                double temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                //printf("%f, %f\n", current->value, current->next->value);
            }
            current = current->next;
            //printf("edge of loop, %f\n", current->value);
        }
    }
    //printBuckets(head);
    //printf("\n");
}

int Length(struct item *listhead) {
    int length = 1; //since index starts at 0, length is 1+index
    struct item * temp = listhead;

    if (listhead->value < 0) {
         return 0; //empty list
    };

    while (temp->next != NULL) { //while it has a neighbor
        length += 1;
        temp = temp->next;
    }

    return length;
};
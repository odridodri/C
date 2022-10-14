/*
Queue implementation using circular array with functions
Variables are global to avoid dealing with pointers 
*/
#include <stdio.h>
#define MAXQUEUESIZE 5
int Add(int item);
int Remove();
int PrintQueue();

int sp = 0, firstEl = 0, nextIt = 0; 				// Queue pointer; index of next empty array element
int queue[MAXQUEUESIZE];	// Queue

int main()
{
	int j;
	
	Add(1);
	Add(2);
	Add(3);
	Add(5);
	
	PrintQueue();

	int valReturned = Remove();
	printf("Removed value is = %d\n",valReturned);

	Remove();
	
	PrintQueue();
	
	return 0;
}

// function to Add an element onto the queue
int Add(int item)
{
		if(sp < MAXQUEUESIZE)
		{
			queue[nextIt]=item;
			nextIt = (nextIt+1)%MAXQUEUESIZE;
            sp+=1;
			return 0;
		}
		else 
		{
			printf("Insertion error; queue is full\n");
			return 1;
		}
}

// function to delete an element from the queue
// variables are global
int Remove()
{
	int returnValue;
	if(sp>0) 
	{		
		returnValue = queue[firstEl];	// COMPLETE
        firstEl = (firstEl+1)%MAXQUEUESIZE;
        sp = sp-1;
		printf("removing %d from queue\n",returnValue);
	}
	else
	{
		printf("Deletion error; queue is empty\n");
		returnValue = -1;
	}	
	return(returnValue);
}

// function to print out queue elements
// variables are global
int PrintQueue()
{
	if(sp>0)
	{
		int j;
		printf("queue contents: ");
		for (j = 0; j < sp; j++)
		{
			printf("%d ",queue[j]);
		}
		printf("\n");
		return 0;
	}
	else
	{
		printf("Printing error; queue is empty\n");
		return -1;
	}
}

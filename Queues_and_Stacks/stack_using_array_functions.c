/*
Simple stack implementation using an array with functions
Variables are global to avoid dealing with pointers 
*/
#include <stdio.h>
#define MAXSTACKSIZE 100
int Push(int item);
int Pop();
int PrintStack();

int sp = 0; 				// stack pointer; index of next empty array element
int stack[MAXSTACKSIZE];	// stack

int main()
{
	int j;
	
	Push(1);
	Push(2);
	Push(3);
	Push(5);
	
	PrintStack();

	int valReturned = Pop();
	printf("popped value is = %d\n",valReturned);

	Pop();
	
	PrintStack();
	
	return 0;
}

// function to push an element onto the stack
int Push(int item)
{
		if(sp < MAXSTACKSIZE)
		{
			stack[sp]=item;
			sp+=1;
			return 0;
		}
		else 
		{
			printf("Insertion error; stack is full\n");
			return 1;
		}
}

// function to delete an element from the stack
// variables are global
int Pop()
{
	int returnValue;
	if(sp>0) 
	{		
		returnValue = stack[sp-1];
		sp = sp-1;
		printf("removing %d from stack\n",returnValue);
	}
	else
	{
		printf("Deletion error; stack is empty\n");
		returnValue = -1;
	}	
	return(returnValue);
}

// function to print out stack elements
// variables are global
int PrintStack()
{
	if(sp>0)
	{
		int j;
		printf("stack contents: ");
		for (j = 0; j < sp; j++)
		{
			printf("%d ",stack[j]);
		}
		printf("\n");
		return 0;
	}
	else
	{
		printf("Printing error; stack is empty\n");
		return -1;
	}
}

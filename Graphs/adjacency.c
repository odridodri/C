// adjacency matrix for a graph
#include <stdio.h>
#define NODES 5

// print nodes in 1d order
void print1dOrder(int * graphArray1d);
// print nodes in tabular format, so that it looks like the 2d matrix above
void printTabular(int * graphArray1d);
// print a list of ordered pairs (i,j) where there is a node from i to j
void printOrderedPairs(int * graphArray1d);
// for input node basenode, print a list of the nodes where there is an edge from basenode
void printAdjacentNodes(int basenode, int * graphArray1d);
// add an edge from node1 to node2 or give a message if there is already such an edge
void addEdge(int node1, int node2, int * graphArray1d);
// return 1 if there is an edge from node1 to node 2, return 0 otherwise
int areConnected(int node1, int node2, int * graphArray1d);
// return 1 if the graph is undirected (symmetric), return 0 otherwise
int isUndirected(int * graphArray1d);
// return the in-degree of the input node basenode
int inDegree(int basenode, int * graphArray);
// return the in-degree of the input node basenode
int outDegree(int basenode, int * graphArray);

int main()
{
	// this is an undirected graph (symmetric matrix)
	/*int graph2d[NODES][NODES] = 
			{ {0, 1, 1, 0, 1},
		      {1, 0, 1, 0, 0},
			  {1, 1, 0, 1, 0},
			  {0, 0, 1, 0, 1},
			  {1, 0, 0, 1, 0} };
	*/		  
	// this is a directed graph
	
	int graph2d[NODES][NODES] = 
			{ {0, 1, 0, 1, 1},
		      {0, 0, 1, 1, 0},
			  {1, 1, 0, 1, 0},
			  {1, 0, 1, 0, 1},
			  {0, 0, 1, 0, 0} };
	

	int graph1d[NODES*NODES];
	int i,j;

// set up a 1d array from the 2d array to use for the remaining operations
	for (i=0; i<NODES; i++)
	{
		for (j=0; j<NODES; j++)
		{
			graph1d[i*NODES+j] = graph2d[i][j];
		}
	}	
	
	print1dOrder(graph1d); // you'll probably want to comment out this line at some point
	printTabular(graph1d);
	printOrderedPairs(graph1d);
	printAdjacentNodes(4, graph1d);
	addEdge(1, 3, graph1d);
	printTabular(graph1d);
	areConnected(4, 3, graph1d);
	inDegree(4, graph1d);
	outDegree(4, graph1d);
	printf("Is Undirected?: %d\n",isUndirected(graph1d));

	return 0;
}

void print1dOrder(int * graphArray1d)
{
	for (int i=0; i<NODES*NODES; i++)
		printf("a[%d] = %d\n",i,graphArray1d[i]);
}

// print nodes in tabular format, so that it looks like the 2d matrix given initially
void printTabular(int * graphArray1d)
{
	int i, j;
	for (i = 0; i < NODES; i++) {
		for (j = 0; j < NODES; j++){
			if (j == 0 ) {
				printf("{%d,", *(graphArray1d + i*NODES + j));
			} else if (j==(NODES-1)) {
				printf("%d}\n", *(graphArray1d + i*NODES + j));
			} else {
				printf( "%d,",  *(graphArray1d + i*NODES + j));
			}
		}
	}
}

// print a list of ordered pairs (i,j) where there is a node from i to j
void printOrderedPairs(int * graphArray1d)
{
	int i,j;
	for (i = 0; i < NODES; i++) {
		for (j = 0; j < NODES; j++){
			if (*(graphArray1d + i*NODES + j)==1 ) {
				printf("(%d, %d)\n", i,j);
			}
		}
	}
}

// for input node basenode, print a list of the nodes where there is an edge from basenode
void printAdjacentNodes(int basenode, int * graphArray1d)
{
	//print every index where row = 1
	int j = 0;

	for (j=0; j< NODES; j++) {
		if (*(graphArray1d + basenode*NODES + j)==1 ) {
			printf("%d, ", j);
		}
	}
	printf("\n");

}

// add an edge from node1 to node2 or give a message if there is already such an edge
void addEdge(int node1, int node2, int * graphArray1d)
{
	int j = 0;

	if (areConnected(node1,node2, graphArray1d) ) {
		printf("Already has an edge.\n");
	} else {
		*(graphArray1d+node1*NODES+node2)=1;
		*(graphArray1d+node2*NODES+node1)=1;
	}
}
	


// return 1 if there is an edge from node1 to node 2, return 0 otherwise
int areConnected(int node1, int node2, int * graphArray1d)
{
	int j = 0;

	if (*(graphArray1d + node1*NODES + node2)==1 ) {
		printf("They're connected\n");
		return 1;
	} else {
		return 0;
	}
}

// return 1 if the graph is undirected (symmetric), return 0 otherwise
int isUndirected(int * graphArray1d)
{
	int i=0, j = 0, isU = 0;
	for (i = 0; i < NODES; i++) {
		for (j = 0; j < NODES; j++){
			if (*(graphArray1d + i*NODES + j)==1 ) {
				if (*(graphArray1d + j*NODES + i)==1 ) {
					isU = 1;
				} else {
					isU = 0;
				};
			} else {
				isU=0;
			}
		}
	}
	return isU;
	
}

// return the in-degree of the input node basenode
int inDegree(int basenode, int * graphArray)
{
	int i = 0, count = 0;
	for (i = 0; i< NODES; i++){
		if (*(graphArray+i*NODES + basenode)==1){
			count+=1;
		}
	}
	printf("%d nodes are in degree from %d.\n", count, basenode);

	return count;
}

// return the out-degree of the input node basenode
int outDegree(int basenode, int * graphArray)
{
	int i = 0, count = 0;
	for (i = 0; i< NODES; i++){
		if (*(graphArray+basenode*NODES + i)==1){
			count+=1;
		}
	}

	printf("%d nodes are out degree from %d.\n", count, basenode);

	return count;
}

#include <stdio.h>

#define MAXEDGES 5

int addEdge(int node1, int node2, int *graph);
void printOrderedPairs(int *graph);
void printAdjacentNodes (int node, int *graph);
int areConnected(int node1, int node2, int *graph);


int main() {
    int len = 2*MAXEDGES;
    int graph[len];

    for (int i=0; i<len; i++) {
        graph[i] = -1;
     //   printf("%d\n\n",graph[i]);
    }

    addEdge(4,3,graph);
    addEdge(3,4, graph);
    addEdge(5,2, graph);
    addEdge(4,8,graph);
    addEdge(3,8, graph);
    addEdge(4,8, graph);
    addEdge(4,3,graph);
    printOrderedPairs(graph);
    printAdjacentNodes (3, graph);
    printAdjacentNodes (4, graph);

    printf("%d\n",areConnected(4,3,graph));
    printf("%d\n",areConnected(5,1,graph));
}

int addEdge(int node1, int node2, int *graph)
{
    int i;
    int j;
    for (i = 0; i< MAXEDGES; i++) {
        if (graph[i*2] == node1) {
            if (graph[2*i+1]== node2) {
                printf("Edge exists\n");
                return 0;
            }
        } else {
            if (graph[i*2] == -1) {
                graph[i*2] = node1;
                graph[i*2+1] = node2;
                printf("Successfully Added\n");
                return 1;
            } else {
                continue;
            }
        }
    }
}

void printOrderedPairs(int *graph) {
    for (int i = 0; i< MAXEDGES; i++) {
        int j = graph[2*i];
        int k = graph[2*i+1];
        if (j != -1) {
            if (i==0) {
                printf("Ordered Pairs:\n");
            }
            printf("(%d, %d)\n",j, k);
        }
    }
};

void printAdjacentNodes (int node, int *graph) {
    int i;
    for (i = 0; i< MAXEDGES; i++) {
        int j = graph[2*i];
        int k = graph[2*i+1];
        if (i==0) {
            printf("Adjacent Nodes for %d:\n", node);
        }
        if (j == node) {
            printf("(%d, %d)\n",j, k);
        }
    }
};

int areConnected(int node1, int node2, int *graph) {
    for (int i = 0; i< MAXEDGES; i++) {
        if (graph[i*2] == node1 && graph[2*i+1]== node2) {
                return 1;
        }
    }

    return 0;
}

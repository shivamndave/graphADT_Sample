//Shivam Dave sdave : Program 5

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int dist = 0;
struct graph{
    int verts;
    struct list* array;
    struct list* queue;
    struct list* parent;
};
 
struct graph *newGraph(int vert);

void doBFS(struct graph* graph, int from, int vNum, int pr);

void pushSource(struct graph* graph, int from, int pushon);

void popSource(struct graph* graph, int from);

void getPathTo(struct graph* graph, int from, int to);

void printGraph(struct graph* graph);

void addEdge(struct graph* graph, int from, int to);
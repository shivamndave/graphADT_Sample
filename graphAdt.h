#include <stdio.h>
#include <stdlib.h>

//Used by visited to tell which have been visited.
#define true 1
#define false 0

//Global variables used by getPathTo & doBFS
int dist = 0;
int *visited;

//Struct graph layout that holds 3 lists and a int of the number of vertices
	//verts: Number of vertices in the file
	//array: array of linked lists where each number in the array is a vertice
	//queue: queue used during BFS to implement the search
	//Parent: single node used to hold a parent node int value to be referenced by
			//getPathTo
struct graph{
	 int verts;
	 struct list* array;
	 struct list* queue;
	 struct list* parent;
};

/*Constructs a new graph that contains adjacency list, queue
 *parent nodes, and number of vertices. Uses number of vertices to 
 *malloc a new graph that uses add edge to add edges to associated
 *with a vertice */
	//PREcondition: no graph existing size of vNum
	//POSTcondition: graph (array of lists)returned of size vNum
struct graph *newGraph(int vNum);

/*Adds a new edge to a graph from a parent vertice to a child
 *node. Adds to a graph specified when called. graph must exist
 *prior to calling this ADT */
	//PREcondition: Blank graph, or incomplete graph
	//POSTcondition: Graph's vertice's list contains edge 'to'
void addEdge(struct graph* graph, int from, int to);

/*Performs Breadth First Search on specified graph from specified
 *vertice until all possible edges are reached.Instead of a color
 *queue the BFS uses a visited array (like color true=grey/black
 *& false = white) to keep track of nodes visited. Also uses a source
 *variable to safely change from int without causing warnings/seg faults
 *The BFS is used to later get a path from one node to another. Also
 *the BFS records parents in the parent list in order to return each 'greyed'
 *parent for use later by get path to.*/
	//PREcondition: BFS search not perfomed. Queue/visited not initialized
	//POSTcondition: Prints out BFS or simply performs BFS, recording parents
void doBFS(struct graph* graph, int from, int vNum, int pr);

/*Used by BFS in order to push items onto the queue used in
 * the BFsearch.*/
	//PREcondition: item not in queue
	//POSTcondition: item at front of queue
void pushSource(struct graph* graph, int from, int pushon);

/*Used by BFS in order to pop items off the queue used in
 * the BFsearch.*/
	//PREcondition: item at front of queue
	//POSTcondition: item not at front of queue, front moves to next node
void popSource(struct graph* graph, int from);

/*Uses info from the BFS in order to find path from a vertice to another
 *one specified by the file 'input'. If you are at the specified to vertice
 *Then it prints it, then works back the to vertice. Using the parent nodes of
 *each vertice found on the path, it is able to print it out. IF the to vertice
 *has no parent, then NO PATH FOUND is printed. Uses recursion to iterate through
 *the parent nodes.*/
	//PREcondition: BFSed graph from specifed from vertice & parent info for that
				  //vertice is found
	//POSTcondition: Prints the path from one node to another using parent node info from BFS.
void getPathTo(struct graph* graph, int from, int to);

/*This prints out the graph using the file information inputted. This output is plain
 *and simply prints out the vertice, along with the each of its edges next to it. I mainly
 * used this for debugging, however it is helpful and informational so the user does not
 * have to open the file. */
	//PREcondition: Graph made, however possibly not printed yet
	//POSTcondition: Graph printed with each vertice followed by its edges
void printGraph(struct graph* graph);

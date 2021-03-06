#include "graphAdt.h"
#include "listAdt.c"

//Creates a new graph for the associated file given and initializes
//A queue, array, associated parent of vertice, and the verts int
//for the new graph
struct graph *newGraph(int vNum){
	 struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
	 graph->verts = vNum;
	 graph->array = (struct list*) malloc(vNum * sizeof(struct list));
	 graph->queue = (struct list*) malloc(vNum * sizeof(struct list));
	 graph->parent = (struct list*) malloc(vNum * sizeof(struct list));
	 int i;
	 for (i = 0; i < vNum; i++) graph->array[i].front = NULL;
	 return graph;
}

//Adds a new edge for a vertice found in the file
void addEdge(struct graph* graph, int from, int to){
	 struct node* newNode = makeNode(to);
	 newNode->next = graph->array[from].front;
	 graph->array[from].front = newNode;
}

//Pushes onto queue used by BFS to hold searched vertices
void pushSource(struct graph* graph, int from, int pushon){
	 struct node* newNode = makeNode(pushon);
	 newNode->next = graph->queue[from].front;
	 graph->queue[from].front = newNode;
}

//Pops off queue used by BFS to hold searched vertices
void popSource(struct graph* graph, int from){
	 struct node* tmpNode = graph->queue[from].front;
	 graph->queue[from].front = graph->queue[from].front->next;
	 free(tmpNode);
}

//Performs a BFS that reaches all possible nodes able to
//From a designated starting node
void doBFS(struct graph* graph, int from, int vNum, int pr){
	 int visited[vNum];
	 int source = from;
	 int i = 0;
	 struct node* newNode = makeNode(-1);
	 for(; i<vNum; i++){
			graph->parent[i].front = newNode;
			visited[i] = false;
	 }
	 visited[source] = true;
	 graph->parent[i].front = newNode;
	 pushSource(graph, from, source);
	 
	 while(graph->queue[from].front != NULL){
			source = graph->queue[from].front->data;
			if(pr == true){
				 if(from == source) printf("Vertice %d: ", source);
				 else printf("%d ", source);
			}
			popSource(graph, from);
			struct node* sNode = makeNode(source);
			struct node* look = graph->array[source].front;
			while (look){
				 if(visited[look->data] == false){
						visited[look->data] = true;
						graph->parent[look->data].front = sNode;
						pushSource(graph, from, look->data);
				 }
				 look = look->next;
			}
	 }
}

//Uses info found from BFS to find path from a node specified
//To another node specified. A counter is used to calculate the 
//distance during this. 
void getPathTo(struct graph* graph, int from, int to){
	 if(from == to){
			dist = -1;
			printf(" %d is ", from);
	 }
	 else if(graph->parent[to].front->data == -1){
			dist = 0;
			printf("%s ", " NO PATH EXISTS");
			return;
	 }
	 else getPathTo(graph, from, graph->parent[to].front->data);
	 dist++;
	 printf("%d ", to);
}

//Prints out the graph made in the file each vertice 
//is printed followed by all edges connected to it
void printGraph(struct graph* graph){
	 int v;
	 for (v = 0; v < graph->verts; v++){
			struct node* look = graph->array[v].front;
			printf("Vertice(%d) ", v);
			while (look){
				 printf(" %d", look->data);
				 look = look->next;
			}
			printf("\n");
	 }
}

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "structures.h"

#define WHITE 0 //undiscovered
#define GRAY 1 //discovered
#define BLACK 2 //visited

/*
  Definitions for Edge, Vertex, and Graph data structures
 */

typedef struct _edge
{
  struct _edge	*next;	/* to form list of edges for a vertex */
  int weight;		/* weight field for use if appropriate */
  int vertex;		/* for edges in the same list, this will be the same */
  int other_vertex;	/* identifies the other endpoint of the edge */
} Edge;

typedef struct _vertex
{
  int weight;		/* weight field for use if appropriate */
  int color;		/* additional fields to support various algorithms */
  int d;
  int f;
  int pred;
  Edge *adj;		/* point to list of edges for adjacent vertices */
  double x;		/* vertex coordinates for drawing graphs on screen */
  double y;
} Vertex;

typedef struct _graph
{
  enum {UNDIRECTED, DIRECTED} type;
  int num_vertices;
  int num_edges;
  Vertex *v;		/* array of vertex structures */
} Graph;

/* at the time a graph is created, the number of vertices must be known
   and an array of that size should be allocated for the 'v' field */

/* normally, the number of edges should also be known at the time that
   a graph is created; although the edges need not be allocated as an array,
   that can certainly be done, and a pointer for each edge element in the array
   can be used when forming the linked lists for adjacency */

/* the structures above can also be used when the number of vertices is fixed,
   but the number of edges vary (i.e., add or remove edges dynamically
   from the adjacency lists, and adjust the 'num_edges' field appropriately) */

/* if the number of vertices is also dynamic for a particular application,
   the 'realloc' library routine could be used to adjust the size of array
   pointed to by the 'v' field; vertex elements would have to be copied/moved
   if removing a vertex in the middle of the array, and in any case of removal,
   any edges associated with the vertex to be removed would have to be found
   in any of the adjacency lists and removed; in short, a fully dynamic graph
   presents some additional complexity */


/*
  Declarations for functions related to graphs using the above structures
*/

// For Graph Consumption
typedef enum {DFS, BFS} traversalType;
Graph* readGraphFromFile(const char* filename);
void addEdge(Graph* g, int from, int to);
void printGraph(Graph* g);
void freeGraph(Graph* g);
void printGraphTraversal(Graph *g, traversalType type);
void printPath(Graph *g, int s, int v);
Graph* transposeGraph(Graph* g);
Graph* createGraph(int num_vertices);
void initializeSingleSource(Graph *g, int source);
void printConnected(Graph *g, int v);

// Graph Algorithms

// Depth First Search Related
void gDFS (Graph *g, int s, Stack* stack);
void gDFS_V(Graph *g, int i, Stack* stack);
void stronglyConnectedComponents(Graph *g);
Node** topologicalSort(Graph *g);

// Breadth First Search Related
void gBFS(Graph *g, int s);

#endif /* _GRAPH_H_ */

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

#define MAX_LINE 256

Graph* readGraphFromFile(const char* filename);
void addEdge(Graph* g, int from, int to);
void printGraph(Graph* g);
void freeGraph(Graph* g);
void printPath(Graph *g, int s, int v);
void printGraphTraversal(Graph *g, traversalType type);

Graph* readGraphFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Skip the first three lines
    char line[MAX_LINE];
    for (int i = 0; i < 3; i++) {
        if (!fgets(line, sizeof(line), file)) {
            perror("Error reading header lines");
            fclose(file);
            return NULL;
        }
    }

    // Read vertices and edges count
    int vertices, edges;
    if (fscanf(file, "%d %d", &vertices, &edges) != 2) {
        perror("Error reading vertices and edges count");
        fclose(file);
        return NULL;
    }

    // Allocate memory for the graph
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_vertices = vertices;
    g->num_edges = edges;
    g->v = (Vertex*)calloc(vertices, sizeof(Vertex));

    // Read edges
    int from, to;
    while (fscanf(file, "%d %d", &from, &to) == 2) {
        addEdge(g, from, to);
    }

    fclose(file);
    return g;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int from, int to) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->other_vertex = to;
    newEdge->next = g->v[from].adj;
    g->v[from].adj = newEdge;
}

// Function to print the graph
void printGraph(Graph* g) {
    printf("Graph with %d vertices and %d edges:\n", g->num_vertices, g->num_edges);
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:", i);
        Edge* current = g->v[i].adj;
        while (current) {
            printf(" -> %d", current->other_vertex);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free the graph memory
void freeGraph(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        Edge* current = g->v[i].adj;
        while (current) {
            Edge* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(g->v);
    free(g);
}

// Print all edges
void printGraphTraversal(Graph *g, traversalType type) {
    switch(type){
        case BFS:
            printf("\nBFS Traversal Results:\n");
            break;
        case DFS:
            printf("\nDFS Traversal Results:\n");
            break;
        default:
            printf("\nTraversal Results:\n");
            break;
    }
    printf("Vertex\tDiscovery Time\tFinish Time\tPredecessor\tColor\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d\t%d\t\t%d\t\t", i, g->v[i].d, g->v[i].f);
        if (g->v[i].pred == -1) {
            printf("None\t\t%d\n", g->v[i].color);
        } else {
            printf("%d\t\t%d\n", g->v[i].pred, g->v[i].color);
        }
    }
}

// Transpose Graph
Graph* transposeGraph(Graph* g) {
    // Create a new graph with the same number of vertices
    Graph* gt = createGraph(g->num_vertices);  

    // Iterate through each vertex of the original graph
    for (int u = 0; u < g->num_vertices; u++) {
        // Traverse the adjacency list of vertex u
        Edge* adj_list = g->v[u].adj;
        
        // For each edge (u -> v), add (v -> u) to the transposed graph
        while (adj_list != NULL) {
            int v = adj_list->other_vertex;  // Destination vertex of the edge

            // Add the reversed edge v -> u to the transposed graph
            addEdge(gt, v, u);  // Reverse the direction of the edge

            adj_list = adj_list->next;  // Move to the next edge
        }
    }

    return gt;  // Return the transposed graph
}



Graph* createGraph(int num_vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->v = (Vertex*)malloc(num_vertices * sizeof(Vertex));
    
    for (int i = 0; i < num_vertices; i++) {
        g->v[i].adj = NULL;  // Initialize adjacency list to NULL
    }

    return g;
}



// Print path from start to vertex
void printPath(Graph *g, int s, int v){
    if (v == s){
        printf("%d\n",s);
    } else if (g->v[v].pred == -1){
        printf("No path from %d to %d.", s, v);
    } else {
        printPath(g, s, g->v[v].pred);
        printf("%d\n", v);
    }
}

#include <limits.h> // For INT_MAX

void initializeSingleSource(Graph *g, int source) {
    for (int i = 0; i < g->num_vertices; i++) {
        g->v[i].d = INT_MAX;  // Set distance to infinity for all vertices
        g->v[i].pred = -1;    // No predecessor initially
    }
    g->v[source].d = 0;       // Distance to source is 0
}

void printConnected(Graph *g, int v) {
    while (g->v[v].adj != NULL) {
        printf("Vertex %d connected to %d\n", v, g->v[v].adj->other_vertex);
        g->v[v].adj = g->v[v].adj->next;
    }
}
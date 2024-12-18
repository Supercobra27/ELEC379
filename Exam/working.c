#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "structures.h"

#define CREATE(NUM, TYPE) (TYPE *) calloc(NUM, sizeof(TYPE))

int time = 0;
Node* head = NULL;

int main() {
    const char* filename = "graph.txt";
    Graph* g = readGraphFromFile(filename);
    Graph* gr = transposeGraph(g);

    if (g) {
        //printGraph(g);
        //gBFS(g, 0);
        gDFS(gr, 0, NULL);
        //printGraphTraversal(gr, DFS);
        //stronglyConnectedComponents(g);
        //printPath(g, 0, 20);
        // for (int i = 0; i < gr->num_vertices; i++){
        //     printConnected(gr, i);
        // }
        freeGraph(g);
        freeGraph(gr);
    } else {
        printf("Failed to read the graph from the file.\n");
    }

    return 0;
}



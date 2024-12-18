#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "disjoint_set.h"

DisjointSet KruskalMST(Graph *g, int w){
    DisjointSet* A = createDisjointSet(81);

    for(int i = 0; i < g->num_vertices; i++) { 
        makeSet(A, g->v[i].pred);
    }

    return;
}
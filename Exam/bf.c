#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "relax.c"

bool BellmanFord(Graph *g, int w, int s){
    initializeSingleSource(g, s);
    for (int i = 1; i < g->num_vertices-1; i++){
        while (g->v[i].adj != NULL) { 
            Relax(g, g->v[i].adj);
            g->v[i].adj = g->v[i].adj->next;
        }
    }
    for (int i = 1; i < g->num_vertices-1; i++){
        while (g->v[i].adj != NULL) {
            if (g->v[i].d > g->v[g->v[i].adj->other_vertex].d + g->v[i].adj->weight) {
                return false;
            }
        }
    }
    return true;
}
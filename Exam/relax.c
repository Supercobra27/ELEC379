#include "graph.h"
#include <stdio.h>

void Relax(Graph *g, Edge *e) {
    Vertex *u = &g->v[e->vertex];
    Vertex *v = &g->v[e->other_vertex];
    int weight = e->weight;
    int temp_d;

    if (v->d > u->d + weight) {
        temp_d = v->d;
        v->d = u->d + weight;
        v->pred = e->vertex;
        printf("\tVertex %d : %d -> %d", e->other_vertex, temp_d, v->d);
    }
}
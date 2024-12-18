#include "graph.h"
#include <stdio.h>

void Relax(Graph *g, Edge *e, int *flag_ptr){
		Vertex *u = &g->v[e->vertex];
		Vertex *v = &g->v[e->other_vertex];
		int edge_weight = e->weight;
		if (v->d > u->d+edge_weight){
			*flag_ptr = 1;
			int temp_d = v->d;
			v->d = u->d+edge_weight;
			v->pred = e->vertex;
			printf("\tVertex %d estimate changed from %d to %d\n", e->other_vertex, temp_d, v->d);
			
		}
}
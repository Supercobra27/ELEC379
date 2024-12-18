#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "structures.h"

extern int time;

void gBFS(Graph *g, int s){
    for(int i = 0; i < g->num_vertices; i++){
        g->v[i].color = WHITE;
        g->v[i].d = -1;
        g->v[i].pred = -1;
        g->v[i].f = 0;
    }

    g->v[s].color = GRAY;
    g->v[s].d = 0;
    g->v[s].pred = -1;

    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q) {
        perror("Failed to allocate memory for the queue");
        exit(EXIT_FAILURE);
    }
    int curr, id;
    initQueue(q);

    enqueue(q, s);
    while (!isEmpty(q)){
        curr = dequeue(q);
        Edge* adj_list = g->v[curr].adj;
        while(adj_list != NULL){
            id = adj_list->other_vertex;
            if (g->v[id].color == WHITE){
                g->v[id].color = GRAY;
                g->v[id].d = g->v[curr].d + 1;
                g->v[id].pred = curr;
                enqueue(q, id);
            }
            adj_list = adj_list->next;
        }
        g->v[curr].color = BLACK;
    }
}
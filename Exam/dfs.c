#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "structures/stack.h"

extern int time;
extern Node* head;

void gDFS(Graph *g, int s, Stack* stack){
   for (int i = 0; i < g->num_vertices; i++){
      g->v[i].color = WHITE;
      g->v[i].pred = -1;
   }

   time = 0;

   for (int i = 0; i < g->num_vertices; i++){
      if (g->v[i].color == WHITE) {
         gDFS_V(g, i, stack);
      }
   }

   //printGraphTraversal(g, DFS);
}

void gDFS_V(Graph *g, int i, Stack* stack){
   int id;
   Edge* adj_list = g->v[i].adj;
   Vertex *curr;
   time++;
   g->v[i].d = time;
   g->v[i].color = GRAY;
   while(adj_list != NULL){
      id = adj_list->other_vertex;
      curr = &g->v[id];
      if(curr->color == WHITE){
         curr->pred = i;
         gDFS_V(g, id, stack);
      }
      adj_list = adj_list->next;
   }
   time++;
   g->v[i].f = time;
   g->v[i].color = BLACK;
   if (stack != NULL){
    push(stack, i);
   }

    //insertEnd(&head, i);
}

void stronglyConnectedComponents(Graph *g) {
    Stack stack;
    initStack(&stack);

    gDFS(g, 0, &stack);

    Graph* gr = transposeGraph(g);

    int prev;

    for (int i = 0; i < g->num_vertices; i++) {
        prev = g->v[i].color;
        g->v[i].color = WHITE;
        //printf("COLOR OF VERTEX %d - %d - %d\n", i, prev, g->v[i].color);
    }

    printf("\n");
    for (int i = 0; i < gr->num_vertices; i++) {
        prev = gr->v[i].color;
        gr->v[i].color = WHITE;
        gr->v[i].pred = -1;
        //printf("COLOR OF VERTEX %d - %d - %d\n", i, prev, gr->v[i].color);
    }

    // Step 4: Perform DFS on the transposed graph in the order defined by the stack
    printf("Strongly Connected Components (SCCs):\n");
    while (!isStackEmpty(&stack)) {
        //printf("Curr on Stack: %d\n", peek(stack.top));
        int vertex = pop(&stack);
        // printf("COLOR OF VERTEX - %d\n", gr->v[vertex].color);
        // gr->v[vertex].color = WHITE;
        // printf("COLOR OF VERTEX - %d\n", gr->v[vertex].color);
        if (gr->v[vertex].color == WHITE) {
            printf("SCC starting at vertex %d: ", vertex);
            gDFS(gr, vertex, NULL);  // No need to pass the stack in the second DFS
            printGraphTraversal(gr, BFS);
            printGraph(gr);
            printf("success");
            printf("\n");
        }
    }
}


Node** topologicalSort(Graph *g){
    gDFS(g, 0, NULL);
    return &head;
}
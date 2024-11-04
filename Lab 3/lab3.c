#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

#define CREATE(NUM, TYPE) (TYPE *) calloc(NUM, sizeof(TYPE))

/* declaration of function in library */

void BFS (Graph *g, int s);
void PrintGraph(Graph *g, int show_duplicates);


/* fill in this function with the specified processing on the graph
   after the search has been performed */

void GraphProcessing (Graph *g, int s)
{
}


/* main routine that reads in text file describing a graph
   then performs search and subsequent processing */

int main (int argc, char *argv[])
{
   Graph *g;
   int s;
  
   if (argc != 3)
   {
      printf ("usage: %s <graph_file> <source_vertex>\n", argv[0]);
      return 1;
   }

   g = ReadGraphFile (argv[1]);
   PrintGraph(g, 0);

   if (g != NULL)
   {
      s = atoi (argv[2]);
      if (s < 0 || s > g->num_vertices - 1)
      {
         printf ("source vertex ID must be between 0 and %d\n",
		 g->num_vertices - 1);
	 return 1;
      }

      BFS (g, s);

      GraphProcessing (g, s);
   }
   return 0;
}


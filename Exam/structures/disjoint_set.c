#include <stdio.h>
#include <stdlib.h>
#include "disjoint_set.h"

// Create a disjoint set with a given number of elements
DisjointSet* createDisjointSet(int size) {
    DisjointSet* ds = (DisjointSet*)malloc(sizeof(DisjointSet));
    if (!ds) {
        printf("Memory allocation failed for DisjointSet\n");
        exit(1);
    }

    ds->size = size;
    ds->nodes = (SetNode*)malloc(size * sizeof(SetNode));
    if (!ds->nodes) {
        printf("Memory allocation failed for DisjointSet nodes\n");
        free(ds);
        exit(1);
    }

    // Initialize each element as its own set
    for (int i = 0; i < size; i++) {
        makeSet(ds, i);
    }

    return ds;
}

// Initialize a set with a single element
void makeSet(DisjointSet* ds, int x) {
    ds->nodes[x].parent = x;  // Each node is its own parent initially
    ds->nodes[x].rank = 0;    // Rank is initialized to 0
}

// Find the representative of the set containing x (with path compression)
int findSet(DisjointSet* ds, int x) {
    if (ds->nodes[x].parent != x) {
        ds->nodes[x].parent = findSet(ds, ds->nodes[x].parent);  // Path compression
    }
    return ds->nodes[x].parent;
}

// Union of two sets containing x and y (with union by rank)
void unionSets(DisjointSet* ds, int x, int y) {
    int rootX = findSet(ds, x);
    int rootY = findSet(ds, y);

    // If they are already in the same set, do nothing
    if (rootX == rootY) {
        return;
    }

    // Union by rank
    if (ds->nodes[rootX].rank < ds->nodes[rootY].rank) {
        ds->nodes[rootX].parent = rootY;
    } else if (ds->nodes[rootX].rank > ds->nodes[rootY].rank) {
        ds->nodes[rootY].parent = rootX;
    } else {
        ds->nodes[rootY].parent = rootX;
        ds->nodes[rootX].rank++;
    }
}

// Free the memory allocated for the disjoint set
void freeDisjointSet(DisjointSet* ds) {
    free(ds->nodes);
    free(ds);
}

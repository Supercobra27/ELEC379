#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

// Structure representing a node in a disjoint set
typedef struct SetNode {
    int parent;  // The parent of the node
    int rank;    // The rank (depth) of the node
} SetNode;

// Disjoint set structure
typedef struct DisjointSet {
    SetNode* nodes;    // Array of nodes
    int size;          // Number of elements in the set
} DisjointSet;

// Function prototypes
DisjointSet* createDisjointSet(int size);
void makeSet(DisjointSet* ds, int x);
int findSet(DisjointSet* ds, int x);
void unionSets(DisjointSet* ds, int x, int y);
void freeDisjointSet(DisjointSet* ds);

#endif /* _DISJOINT_SET_H_ */

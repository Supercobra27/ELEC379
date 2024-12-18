CC = gcc
CFLAGS = -Wall -g

# Directories for object files
OBJ_DIR = structures

# Object files for the structures and graph
OBJECTS = $(OBJ_DIR)/node.o $(OBJ_DIR)/queue.o $(OBJ_DIR)/stack.o $(OBJ_DIR)/linked_list.o $(OBJ_DIR)/disjoint_set.o graph.o

# Final executable target
EXE = main
LIBRARY = structures

# Rule to build the final executable
$(EXE): working.o $(LIBRARY)
	$(CC) $(CFLAGS) -o $(EXE) working.o dfs.o bfs.o $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs structures.a $(OBJECTS)
	$(MAKE) clean

# Compile the working file (main program)
working.o: working.c
	$(CC) $(CFLAGS) -c working.c

# Compile graph.c into graph.o
graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

# Compile node.c into node.o and place it in the 'structures' directory
$(OBJ_DIR)/node.o: structures/node.c structures/node.h
	$(CC) $(CFLAGS) -c structures/node.c -o $(OBJ_DIR)/node.o

# Compile queue.c into queue.o and place it in the 'structures' directory
$(OBJ_DIR)/queue.o: structures/queue.c structures/queue.h
	$(CC) $(CFLAGS) -c structures/queue.c -o $(OBJ_DIR)/queue.o

# Compile stack.c into stack.o and place it in the 'structures' directory
$(OBJ_DIR)/stack.o: structures/stack.c structures/stack.h
	$(CC) $(CFLAGS) -c structures/stack.c -o $(OBJ_DIR)/stack.o

# Compile linked_list.c into linked_list.o and place it in the 'structures' directory
$(OBJ_DIR)/linked_list.o: structures/linked_list.c structures/linked_list.h
	$(CC) $(CFLAGS) -c structures/linked_list.c -o $(OBJ_DIR)/linked_list.o

# Compile disjoint_set.c into disjoint_set.o and place it in the 'structures' directory
$(OBJ_DIR)/disjoint_set.o: structures/disjoint_set.c structures/disjoint_set.h
	$(CC) $(CFLAGS) -c structures/disjoint_set.c -o $(OBJ_DIR)/disjoint_set.o

# Compile dfs.c into dfs.o
dfs.o: dfs.c structures.h
	$(CC) $(CFLAGS) -c dfs.c

# Compile bfs.c into bfs.o
bfs.o: bfs.c structures.h
	$(CC) $(CFLAGS) -c bfs.c

# Clean target to remove object files and executables
clean:
	del /q $(OBJ_DIR)\node.o $(OBJ_DIR)\queue.o $(OBJ_DIR)\stack.o $(OBJ_DIR)\linked_list.o $(OBJ_DIR)\disjoint_set.o graph.o working.o $(EXE)

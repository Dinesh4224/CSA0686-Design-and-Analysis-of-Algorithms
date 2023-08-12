#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int V;

bool isSafe(int v, int pos, int path[]) {
	int i;
    if (graph[path[pos - 1]][v] == 0)
        return false;
    
    for ( i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    
    return true;
}

bool hamiltonianCycleUtil(int path[], int pos) {
	int v;
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    
    for ( v = 1; v < V; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(path, pos + 1))
                return true;
            path[pos] = -1;  
        }
    }
    
    return false;
}

bool hamiltonianCycle() {
	int i;
    for ( i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;  
    
    if (!hamiltonianCycleUtil(path, 1)) {
        printf("No Hamiltonian cycle exists.\n");
        return false;
    }
    
    printf("Hamiltonian cycle exists: ");
    for (i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Complete the cycle
    
    return true;
}

int main() {
	int i,j;
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamiltonianCycle();
    return 0;
}


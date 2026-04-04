/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/

code:

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    int *size = malloc(n * sizeof(int));
    int **adj = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        size[i] = 0;
        adj[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u] = realloc(adj[u], (size[u] + 1) * sizeof(int));
        adj[u][size[u]++] = v;
        adj[v] = realloc(adj[v], (size[v] + 1) * sizeof(int));
        adj[v][size[v]++] = u;
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < size[i]; j++) printf(" %d", adj[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(size);

    return 0;
}

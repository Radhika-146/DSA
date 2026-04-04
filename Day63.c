/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order...*/

code:

#include <stdio.h>
#include <stdlib.h>

int n;
int **adj;
int *size;
int *vis;

void dfs(int u) {
    vis[u] = 1;
    printf("%d ", u);
    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
    }
}

int main() {
    scanf("%d", &n);

    adj = malloc(n * sizeof(int*));
    size = malloc(n * sizeof(int));
    vis = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        adj[i] = malloc(size[i] * sizeof(int));
        for (int j = 0; j < size[i]; j++) scanf("%d", &adj[i][j]);
    }

    int s;
    scanf("%d", &s);

    dfs(s);
    return 0;
}

/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
code:
#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int adj[n][n], int visited[n], int *stack, int *top) {
    visited[v] = 1;
    for (int u = 0; u < n; u++)
        if (adj[v][u] && !visited[u])
            dfs(u, n, adj, visited, stack, top);
    stack[++(*top)] = v;
}

void topologicalSort(int n, int adj[n][n]) {
    int visited[n], stack[n], top = -1;
    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, n, adj, visited, stack, &top);

    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    int n = 6;
    int adj[6][6] = {0};

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(n);

    return 0;
}

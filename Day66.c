/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

code:
#include <stdio.h>

int graph[10][10], visited[10], rec[10], n;

int dfs(int v) {
    visited[v] = 1;
    rec[v] = 1;

    for (int u = 0; u < n; u++) {
        if (graph[v][u]) {
            if (!visited[u] && dfs(u))
                return 1;
            else if (rec[u])
                return 1;
        }
    }

    rec[v] = 0;
    return 0;
}

int main() {
    printf("");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        if (!visited[i] && dfs(i)) {
            printf("YES");
            return 0;
        }

    printf("NO");
    return 0;
}

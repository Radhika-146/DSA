/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

code:

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int v) {
    visited[v] = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}

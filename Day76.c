/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

code:

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
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

    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}

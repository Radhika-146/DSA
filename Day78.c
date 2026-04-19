/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

code:

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with large value
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int visited[MAX] = {0};
    int key[MAX];

    // Initialize keys
    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
    }

    key[1] = 0; // start from node 1

    int total_weight = 0;

    for(int i = 1; i <= n; i++) {
        int min = INT_MAX, u;

        // Find minimum key vertex not visited
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        visited[u] = 1;
        total_weight += key[u];

        // Update adjacent vertices
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total_weight);

    return 0;
}

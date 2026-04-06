/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

code:

#include <stdio.h>

int g[1001][1001], vis[1001], n, m, f;

void dfs(int u, int p){
    vis[u] = 1;
    for(int v=1; v<=n; v++){
        if(g[u][v]){
            if(!vis[v]) dfs(v, u);
            else if(v != p) f = 1;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i, -1);
    }
    printf(f ? "YES" : "NO");
    return 0;
}

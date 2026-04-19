#include <stdio.h>
#include <string.h>

#define MAXV 100005
#define MAXE 200005

int head[MAXV], nxt[MAXE], to[MAXE], ecnt;
int disc[MAXV], low[MAXV], par[MAXV], ap[MAXV];
int timer_val, V;

void addEdge(int u, int v) {
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}

void dfs(int u) {
    int children = 0;
    disc[u] = low[u] = timer_val++;

    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = to[e];
        if (v == u) continue;

        if (disc[v] == -1) {
            children++;
            par[v] = u;
            dfs(v);

            if (low[v] < low[u])
                low[u] = low[v];

            if (par[u] == -1 && children > 1)
                ap[u] = 1;

            if (par[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;

        } else if (v != par[u]) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int E, u, v;
    scanf("%d %d", &V, &E);

    memset(head, -1, sizeof(head));
    memset(disc, -1, sizeof(disc));
    memset(par, -1, sizeof(par));
    memset(ap, 0, sizeof(ap));
    ecnt = 0;
    timer_val = 0;

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 0; i < V; i++)
        if (disc[i] == -1)
            dfs(i);

    int found = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found)
        printf("-1");

    return 0;
}

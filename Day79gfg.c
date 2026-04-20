/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.*/



code:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[MAX];
struct Node* rev[MAX];
int visited[MAX];
int stack[MAX], top = -1;

struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->next = NULL;
    return temp;
}

void addEdge(int u, int v) {
    struct Node* temp = newNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u);
    temp->next = rev[v];
    rev[v] = temp;
}

void dfs1(int u) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v])
            dfs1(temp->v);
        temp = temp->next;
    }
    stack[++top] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    struct Node* temp = rev[u];
    while (temp) {
        if (!visited[temp->v])
            dfs2(temp->v);
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < MAX; i++) {
        adj[i] = NULL;
        rev[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int count = 0;

    while (top != -1) {
        int u = stack[top--];
        if (!visited[u]) {
            dfs2(u);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}

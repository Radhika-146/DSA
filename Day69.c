/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

code:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode *arr;
    int size, capacity;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap *h = malloc(sizeof(MinHeap));
    h->arr = malloc(sizeof(HeapNode) * cap);
    h->size = 0;
    h->capacity = cap;
    return h;
}

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a; *a = *b; *b = t;
}

void push(MinHeap *h, int node, int dist) {
    int i = h->size++;
    h->arr[i].node = node;
    h->arr[i].dist = dist;
    while (i && h->arr[(i - 1) / 2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap *h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, s = i;
        if (l < h->size && h->arr[l].dist < h->arr[s].dist) s = l;
        if (r < h->size && h->arr[r].dist < h->arr[s].dist) s = r;
        if (s == i) break;
        swap(&h->arr[i], &h->arr[s]);
        i = s;
    }
    return root;
}

int empty(MinHeap *h) {
    return h->size == 0;
}

int main() {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    Edge **g = malloc(n * sizeof(Edge*));
    int *sz = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) g[i] = malloc(1000 * sizeof(Edge));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u][sz[u]].v = v;
        g[u][sz[u]].w = w;
        sz[u]++;
    }

    int *dist = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[s] = 0;

    MinHeap *h = createHeap(m + 5);
    push(h, s, 0);

    while (!empty(h)) {
        HeapNode x = pop(h);
        int u = x.node, d = x.dist;
        if (d != dist[u]) continue;
        for (int i = 0; i < sz[u]; i++) {
            int v = g[u][i].v;
            int w = g[u][i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(h, v, dist[v]);
            }
        }
    }

    for (int i = 0; i < n; i++) printf("%d ", dist[i]);
    return 0;
}

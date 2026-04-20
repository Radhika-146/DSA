/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

code:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

struct Node* adj[MAX];

struct MinHeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};

void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

struct MinHeapNode extractMin(struct MinHeap* h) {
    struct MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void insertHeap(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].v = v;
    h->heap[i].dist = dist;

    while (i && h->heap[i].dist < h->heap[(i - 1) / 2].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    insertHeap(&h, src, 0);

    while (h.size > 0) {
        struct MinHeapNode min = extractMin(&h);
        int u = min.v;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* temp = newNode(v, w);
        temp->next = adj[u];
        adj[u] = temp;

        temp = newNode(u, w);
        temp->next = adj[v];
        adj[v] = temp;
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}

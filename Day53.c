/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

code:

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Pair {
    Node* node;
    int hd;
} Pair;

Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0) return 0;

    int arr[MAX];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* nodes[MAX];
    for(int i = 0; i < n; i++) {
        if(arr[i] != -1) nodes[i] = createNode(arr[i]);
        else nodes[i] = NULL;
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    Node* root = nodes[0];

    Pair queue[MAX];
    int front = 0, rear = 0;

    int col[MAX][MAX];
    int colSize[MAX] = {0};

    int offset = MAX / 2;

    queue[rear++] = (Pair){root, 0};

    while(front < rear) {
        Pair p = queue[front++];
        Node* curr = p.node;
        int hd = p.hd + offset;

        col[hd][colSize[hd]++] = curr->data;

        if(curr->left)
            queue[rear++] = (Pair){curr->left, p.hd - 1};
        if(curr->right)
            queue[rear++] = (Pair){curr->right, p.hd + 1};
    }

    for(int i = 0; i < MAX; i++) {
        if(colSize[i] > 0) {
            for(int j = 0; j < colSize[i]; j++) {
                printf("%d ", col[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

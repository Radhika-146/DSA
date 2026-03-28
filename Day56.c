/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/

code:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    if (val == -1) return NULL;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int isMirror(Node* a, Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    return (a->data == b->data) && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0) {
        printf("YES");
        return 0;
    }

    Node* nodes[n];
    for (int i = 0; i < n; i++) nodes[i] = newNode(arr[i]);

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            nodes[i]->left = (j < n ? nodes[j] : NULL);
            j++;
            nodes[i]->right = (j < n ? nodes[j] : NULL);
            j++;
        }
    }

    if (isMirror(nodes[0]->left, nodes[0]->right)) printf("YES");
    else printf("NO");

    return 0;
}

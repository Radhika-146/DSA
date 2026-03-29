/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/

code:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    if (val == -1) return NULL;
    Node* n = malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void mirror(Node* root) {
    if (!root) return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* nodes[n];
    for (int i = 0; i < n; i++) nodes[i] = newNode(arr[i]);

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i]) {
            nodes[i]->left = (j < n ? nodes[j] : NULL);
            j++;
            nodes[i]->right = (j < n ? nodes[j] : NULL);
            j++;
        }
    }

    mirror(nodes[0]);
    inorder(nodes[0]);
    return 0;
}


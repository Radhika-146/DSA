/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/

code:

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (arr[i] == value) return i;
    return -1;
}

struct node* build(int pre[], int in[], int start, int end, int *idx) {
    if (start > end) return NULL;
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = pre[*idx];
    (*idx)++;
    if (start == end) {
        root->left = root->right = NULL;
        return root;
    }
    int pos = search(in, start, end, root->data);
    root->left = build(pre, in, start, pos - 1, idx);
    root->right = build(pre, in, pos + 1, end, idx);
    return root;
}

void post(struct node* root) {
    if (!root) return;
    post(root->left);
    post(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    int idx = 0;
    struct node* root = build(pre, in, 0, n - 1, &idx);
    post(root);
}

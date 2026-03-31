/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

code :

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Search in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[],
                       int start, int end, int* postIndex) {

    if (start > end)
        return NULL;

    // Pick root from postorder
    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    // If single node
    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    // ⚠️ Build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter postorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder Traversal:\n");
    preorder(root);

    return 0;
}

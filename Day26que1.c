/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL) {
        return newNode;
    }

    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void displayForward(struct Node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nDoubly Linked List (Forward Traversal):\n");

    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("No nodes to insert.\n");
        return 0;
    }

    printf("Enter %d values:\n", n);

    for(int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    displayForward(head);

    return 0;
}

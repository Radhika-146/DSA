/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node *next;
} Node;

void insertSorted(Node **head, float value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data < value)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float arr[], int n) {
    Node **buckets = (Node **)malloc(n * sizeof(Node *));

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        insertSorted(&buckets[idx], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        Node *temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            Node *del = temp;
            temp = temp->next;
            free(del);
        }
    }

    free(buckets);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.6f ", arr[i]);

    return 0;
}

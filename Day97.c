/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/

code:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int cmp(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index])
            break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0)
        return 0;

    qsort(meetings, n, sizeof(Meeting), cmp);

    int *heap = (int *)malloc(n * sizeof(int));
    int heapSize = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        while (heapSize > 0 && heap[0] <= meetings[i].start)
            pop(heap, &heapSize);

        push(heap, &heapSize, meetings[i].end);

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    free(heap);

    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting *meetings = (Meeting *)malloc(n * sizeof(Meeting));

    for (int i = 0; i < n; i++)
        scanf("%d %d", &meetings[i].start, &meetings[i].end);

    printf("%d\n", minMeetingRooms(meetings, n));

    free(meetings);

    return 0;
}

/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

code:

#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

/* check empty */
int empty() {
    return (front == -1);
}

/* size of deque */
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

/* push at front */
void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = x;
    } else if (front > 0) {
        deque[--front] = x;
    } else {
        printf("Deque Overflow\n");
    }
}

/* push at rear */
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = x;
}

/* pop from front */
void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    front++;

    if (front > rear)
        front = rear = -1;
}

/* pop from rear */
void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    rear--;

    if (rear < front)
        front = rear = -1;
}

/* front element */
int front_element() {
    if (empty()) return -1;
    return deque[front];
}

/* rear element */
int back_element() {
    if (empty()) return -1;
    return deque[rear];
}

/* clear deque */
void clear() {
    front = rear = -1;
}

/* reverse deque */
void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

/* sort deque (ascending) */
void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

/* display deque */
void display() {
    if (empty()) {
        printf("Deque Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

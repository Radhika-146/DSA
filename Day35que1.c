/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/

code:

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push(int x) {
    s1[++top1] = x;
}

void transfer() {
    while (top1 != -1) {
        s2[++top2] = s1[top1--];
    }
}

int pop() {
    if (top2 == -1) {
        transfer();
    }
    return s2[top2--];
}

int peek() {
    if (top2 == -1) {
        transfer();
    }
    return s2[top2];
}

bool empty() {
    return (top1 == -1 && top2 == -1);
}

int main() {
    push(1);
    push(2);

    printf("%d\n", peek());   // 1
    printf("%d\n", pop());    // 1
    printf("%s\n", empty() ? "true" : "false");

    return 0;
}

/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/
code:

#include <stdio.h>

#define MAX 1000

int queue[MAX];
int stack[MAX];

int main()
{
    int n;

    scanf("%d", &n);

    int front = 0, rear = n - 1;
    int top = -1;

    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    for (int i = front; i <= rear; i++)
        stack[++top] = queue[i];

    for (int i = front; i <= rear; i++)
        queue[i] = stack[top--];

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}

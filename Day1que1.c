//Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right

code:
#include <stdio.h>
int main()
{
    int n;
    printf("enter the size of array:");
    scanf("%d",&n);
    int arr[n+1];
    printf("enter the elements of array: ");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    f
    int x;
    int pos;
    printf("\nenter the position:");
    scanf("%d",&pos);
    printf("enter the element to insert:");
    scanf("%d",&x);
    for (int i=n;i>=pos-1;i--){
        arr[i]=arr[i-1];
    }
    
    arr[pos-1]=x;
    printf("\n");
    for (int i=0;i<n+1;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
    





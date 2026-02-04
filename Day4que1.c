//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays

code:

#include <stdio.h>

int main() {
    int n;
    printf("array size:");
    scanf("%d",&n);
    int arr[n];
    printf("enter ther element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    for(int i=0;i<n/2;i++){
        x=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=x;
        
    }
    
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}


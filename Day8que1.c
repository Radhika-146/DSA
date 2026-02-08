/*Day 8 - Question 1: Compute Power Using Recursion
Close
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
  

code:  
  
#include <stdio.h>
int power(int a,int b){
    if(b==0){
        return 1;
    }
    else{
        int m=1;
        m=a*power(a,b-1);
        return m;
    }
    
}
int main(){
    int a,b;
    printf("enter a and b as integers ");
    scanf("%d%d",&a,&b);
    int p=power(a,b);
    printf("%d",p);
    return 0;
}

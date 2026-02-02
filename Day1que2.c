#include <stdio.h>
int main(){
    int n;
    printf("enter the size: ");
    scanf("%d",&n);
    int num[n];
    printf("enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int target;
    printf("enter the target sum:");
    scanf("%d",&target);
    
    int temp;
    int sum=0;
    int x=0;

    for (int i=0;i<n;i++)
    {
        ;
        for(int j=i+1;j<n;j++)
        {
            if(num[i]+num[j]==target)
            {
                printf("[%d,%d]",i,j);
                x=1;
                break;
            }
            if(x==1){
                break;
            }

        }
    }
    return 0;

} 

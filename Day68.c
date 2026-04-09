/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

code:

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int graph[n][n];
    int indeg[n];
    for(int i=0;i<n;i++){
        indeg[i]=0;
        for(int j=0;j<n;j++) graph[i][j]=0;
    }

    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        indeg[v]++;
    }

    int queue[n], front=0, rear=0;
    for(int i=0;i<n;i++)
        if(indeg[i]==0) queue[rear++]=i;

    int count=0;
    while(front<rear){
        int u=queue[front++];
        printf("%d ",u);
        count++;
        for(int v=0;v<n;v++){
            if(graph[u][v]){
                indeg[v]--;
                if(indeg[v]==0) queue[rear++]=v;
            }
        }
    }

    if(count!=n) printf("Cycle");
    return 0;
}

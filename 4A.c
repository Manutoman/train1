#include<stdio.h> 
#include<conio.h> 
int minm(int m,int n) 
{ 
return ((m>n)?n:m); 
} 
void sssp(int cost[20][20],int n,int source,int dest[20]) 
{ 
int s[20],min,w,i,j,v; 
for(i=1;i<=n;i++) 
{ 
s[i]=0; 
dest[i]=cost[source][i]; 
} 
s[source]=1; 
for(i=1;i<=n-1;i++) 
{ 
min=999; 
for(j=1;j<=n;j++) 
if((s[j]==0) && (min>dest[j])) 
{ 
min=dest[j]; 
w=j; 
} 
s[w]=1; 
for(v=1;v<=n;v++) 
if(s[v]==0) 
{ 
dest[v]=minm(dest[v],(dest[w]+cost[w][v])); 
} 
} 
} 
int main() 
{ 
int source,i,j,n; 
int cost[20][20],dest[20]; 
printf("enter no of vertices\n"); 
scanf("%d",&n); 
printf("enter source vertex\n"); 
scanf("%d",&source); 
printf("enter cost matrix\n"); 
for(i=1;i<=n;i++) 
for(j=1;j<=n;j++) 
scanf("%d",&cost[i][j]); 
sssp(cost,n,source,dest); 
printf(":the shortest distance is \n");for(i=1;i<=n;i++) 
printf("the cost from %d to %d is %d\t", source,i,dest[i]); 
getch(); 
}

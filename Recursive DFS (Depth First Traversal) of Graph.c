#include<stdio.h>
#include<stdlib.h>
#define MAX 10


//Initializing the functions

void display_matrix(int );
void insert_matrix(int );
void dfs(int );
int **a;
int n=0;



int main()
{

   int task=0;
   int value;
  int i=0;
  
  printf("\nEnter the values of vertices\n");
  scanf("%d",&n);
  a=(int **)malloc(n * sizeof(int *));
  if(a==NULL)
  {
   printf("\nMemory allocation failed\n");
   return -1;
  }
  for(i=0;i<n;i++)
  {
   a[i]=(int *)malloc(n * sizeof(int));
     if(a[i]==NULL)
    {
     printf("\nMemory allocation failed\n");
     return -2;
    } 
  }
  insert_matrix(n);
  display_matrix(n);
  dfs(0);
}



void insert_matrix(int n)
{
  int i=0,j=0;
  printf("\nInsert the values of adjacency matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
     {  
        a[i][j]=0;
          printf("\nIf there is a directed path from vertice v%d to v%d then enter 1 else 0\n",i+1,j+1);
             scanf("%d",&a[i][j]);
     }
 }
}


void display_matrix(int n)
{
  int i=0,j=0;
  for(i=0;i<n;i++)
   {
   for(j=0;j<n;j++)
    {
     printf("%d\t",a[i][j]);
    }
   printf("\n");
   }
printf("\n\n");
}


int visited[MAX]={0};


void dfs(int i)
{
int v=0,k=0;
visited[i]=1;
printf("v%d ",i+1);
for(k=0;k<n;k++)
if(a[i][k]==1 && visited[k]==0)
dfs(k);
}
                


  




 
     
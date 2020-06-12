#include<stdio.h>
#include<stdlib.h>
struct queue
{
  int data[20];
   int front,rear;
};

int **a;
void init(struct queue *);
void insert_queue(struct queue *,int);
int delete_queue(struct queue *);
void insert_matrix(int);
void display_matrix(int);
void bfs(struct queue *,int);
int isempty(struct queue *);

int main()
{
  int value;
  int i=0,n=0;
  struct queue s;
  printf("\nEnter the number of vertices\n");
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
  bfs(&s,n);
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
          printf("\nIf there is a path from vertice v%d to v%d then enter 1 else 0\n",i+1,j+1);
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
}



void insert_queue(struct queue *s,int val)
{

   s->front++;
     s->data[s->front]=val;
}



int delete_queue(struct queue *s)
{

  s->rear++;
  return s->data[s->rear];
}



void init(struct queue *s)
{
s->front=-1;
s->rear=-1;
}


void bfs(struct queue *s,int n)
{
  printf("\nTraversing BFS\n");
 int i=0,j=0,v=0,w=0;
  int visited[n];
     init(s);

   for(i=0;i<n;i++)
       visited[i]=0;
       v=0;
       visited[v]=1;
       insert_queue(s,v);
       while(! (isempty(s)) )
        {

           v=delete_queue(s);
           printf("v%d\t",v+1);
           for(w=0;w<n;w++)
           {
            if( (a[v][w]==1) && (visited[w]==0))
             {
               insert_queue(s,w);
               visited[w]=1;
             }
           }

        }
  printf("\n");
 }


int isempty(struct queue *s)
{
if(s->front==s->rear)
return 1;
return 0;
}

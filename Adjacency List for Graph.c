#include<stdio.h>
#include<stdlib.h>


struct node
{
 int data;
  struct node *next;
};
struct node *l[10];

int **a;
int v;
void adjlist();


int main()
{
int i=0,j=0;
printf("\nHow many vertices you want to enter\n");
scanf("%d",&v);
a=(int **)malloc(sizeof(int *)*v);
if(a==NULL)
	printf("\nMemory allocation failed\n");
 for(i=0;i<v;i++)
  {
   a[i]=(int *)malloc(sizeof(int)*v);
	 if(a[i]==NULL)
		printf("\nMemory allocation failed\n");
  }
printf("\nEnter the edges\n");
	for(i=0;i<v;i++)
	 for(j=0;j<v;j++)
 	 {
          printf("\nIf there is edge between v%d and v%d then press 1 else 0\n",i+1,j+1);
  	  scanf("%d",&a[i][j]);
  	 }
printf("\nThe adjacency matrix is \n");
	for(i=0;i<v;i++)
 	{
	 for(j=0;j<v;j++)
 	 {
  	 printf("%d\t",a[i][j]);
 	 }
  	 printf("\n");
        }
	adjlist(l);

}



void adjlist()
{
	struct node *temp,*new;
	int i=0,j=0;
 for(i=0;i<v;i++)
  { 
	  l[i]=NULL;
   for(j=0;j<v;j++)
    {
     if(a[i][j]==1)
     {
	     new=(struct node *)malloc(sizeof(struct node));
	     new->next=NULL;
	     new->data=j+1;
      if(l[i]==NULL)
	      temp=l[i]=new;
      else
      {
	      temp->next=new;
	      temp=new;
      }
     }
    }
  }
 temp=NULL;
 printf("\ndisplaying the adjacency list\n");
 for(i=0;i<v;i++)
      {
	     temp=l[i];
	     printf("v%d->",i+1);
		while(temp!=NULL)
		{
	        printf("v%d->",temp->data);
                temp=temp->next;
		}
	  printf("\n");
      }
}
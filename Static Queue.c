#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct queue
{
 int data[MAX];
 int front;
 int rear;
};


void add(struct queue *,int);
int delete(struct queue *);
void display(struct queue *);
int main()
{
	int option=0,n=0,k=0;
	struct queue q;
	q.front=q.rear=-1;
	do
	{
	 printf("\n1)Press 1 to add\n2)Press 2 to delete\n3)Press 3 to display\n4)Press 4 to exit\n");
	 scanf("%d",&option);
	 switch(option)
	 {
	  case 1: if(q.rear==MAX-1)
			  printf("\nThe queue is full\n");
		  else
		  add(&q,n);break;
          case 2: if(q.front > q.rear)
			  printf("\nThe queue is empty\n");
		  else
		  {
		    k=delete(&q);
		    printf("\nThe deleted item is %d\n",k);
		  }break;
          case 3:if(q.front > q.rear)
			 printf("\nThe queue is empty\n");
		 else
			 display(&q);break;
	  case 4: exit(1);break;
	  default : printf("\nYou have entered invalid option\n");break;
	 };	
      }while(1);
}


void add(struct queue *q,int n)
{
 int d=0;
  printf("\nEnter the value to be stored int he queue\n");
  scanf("%d",&d);
   if(q->rear==-1 && q->front==-1)
   {
     q->rear=q->front=0;
     q->data[q->rear]=d;
   }
   else
   {
    q->data[++q->rear]=d;
   } 
}


int delete(struct queue *q)
{
 return q->data[q->front++];
}
void display(struct queue *q)
{
 int i=0,n=0;
 for(i=q->front;i<=q->rear;i++)
  printf("%d ",q->data[i]);
 }


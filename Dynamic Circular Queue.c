#include<stdio.h>
#include<stdlib.h>
struct queue
{
 int data;
 struct queue *next;
};


struct queue *front;
struct queue *rear;
void add();
int delete();
void display();


int main()
{
	int option=0,n=0,k=0;
	do
	{
	 printf("\n1)Press 1 to add\n2)Press 2 to delete\n3)Press 3 to display\n4)Press 4 to exit\n");
	 scanf("%d",&option);
	 switch(option)
	 {
	  case 1:
	         add();break;
      case 2: if(front==NULL)
			  printf("\nThe queue is empty\n");
		  else
		  {
		    k=delete();
		    printf("\nThe deleted item is %d\n",k);
		  }break;
      case 3:if(front==NULL)
			 printf("\nThe queue is empty\n");
		 else
			 display();break;
	  case 4: exit(1);break;
	  default : printf("\nYou have entered invalid option\n");break;
	 };
      }while(1);
}


void add()
{
 int d=0;
 struct queue *new;

  new=(struct queue *)malloc(sizeof(struct queue));
  printf("\nEnter the value to be stored int he queue\n");
  scanf("%d",&d);
  new->data=d;
  new->next=NULL;
   if(front==0)
   {
     rear=front=new;
     new->next=front;
   }
   else
   {
    rear->next=new;
    rear=new;
    new->next=front;
   }

}


int delete()
{
 struct queue *temp;
 int d=0;
 if(front==rear)
 {
  d=front->data;
  front=rear=NULL;
  return d;
 }
 temp=front;
 d=front->data;
 front=front->next;
 rear->next=front;
 free(temp);
 temp=0;
 return d;
}


void display()
{
 struct queue *temp;
 temp=front;
 do{
  printf("%d ",temp->data);
  temp=temp->next;
 }while(temp!=front);

}




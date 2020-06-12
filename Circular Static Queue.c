#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue
{
  int data[MAX];
   int front,rear;
};


void insert(struct queue *s,int n);
void delete(struct queue *s);
void display(struct queue *s);
void peek(struct queue *s);


int main()
{
   struct queue s;
  s.front=-1;
   s.rear=-1;
   int n;
  int value;
      do
          {
                printf("\n Press 1 to insert\n Press 2 to delete\n Press 3 to display\n Press 4 to peek \n Press 5 to stop the program\n\n");
                 scanf("%d",&n);
                  switch(n)
                   {
                        case 1 : 
                                   if( (s.front==0 && s.rear==MAX-1) || (s.front-1==s.rear) )
                                   printf("\nQueue is full\n");
                                        else
                                        {
                                          printf("\nEnter the value to be entered in the queue\n");
                                           scanf("%d",&value);
                                            insert(&s,value);
                                        }
                                       break;
                        case 2 :  if(s.rear==-1 && s.front==-1)   
                                     printf("\nQueue is empty\n");
                                      else 
                                     delete(&s);
                                      break;
                        case 3 :   if(s.rear==-1 && s.front==-1)   
                                     printf("\nQueue is empty\n");
                                            else
                                             display(&s);break;
                        case 4 :   
                                if(s.rear==-1 && s.front==-1)   
                                     printf("\nQueue is empty\n");     
                                    else
                                     peek(&s);
                    };
              }while(n!=5);
}



 void insert(struct queue *s,int n)
{
      
if(s->front==-1 && s->rear==-1)
      {
         s->front=s->rear=0; 
      s->data[s->rear]=n;
      }
 else if(s->front!=0 && s->rear==MAX-1)
 {
       s->rear=0;
     s->data[s->rear]=n;
 }
 else
 {
    s->rear++;
     s->data[s->rear]=n;
      
 }
}


void delete(struct queue *s)
{             
  if(s->front==s->rear)
  {
    printf("The value %d is being deleted",s->data[s->front]);
                       s->front=s->rear=-1;
  }
  else if(s->front==MAX-1)
   {
     printf("The value %d is being deleted",s->data[s->front]);
    s->front=0;
   }
    else
    {
     printf("The value %d is being deleted",s->data[s->front]);
           s->front++; 
     }
}


void peek(struct queue *s)
{         
    printf("\nThe value at last position of queue is %d\n",s->data[s->rear]);
}


void display(struct queue *s)
{
  int i=0;
     printf("\nThe values are\n");
  if(s->front <= s->rear)
  {
   for(i=s->front;i<=s->rear;i++)
    {
     printf("\n %d \n",s->data[i]);
    }
  }
  else
     {  
       for(i=s->front;i<MAX;i++)
          {
              printf("\n%d\n",s->data[i]);
          }
        for(i=0;i<=s->rear;i++)
          {
              printf("\n%d\n",s->data[i]);
          }
     }
 
  
}
#include<stdio.h>
#include<stdlib.h>
//Declaring the structure
struct stack
{
  int data;
  struct stack *next;
}*top=0;
//Initializing the functions
void intilialize(struct stack *);
void display(struct stack *);
void push(int n);
void pop();

//main
int main()
{
   int task=0;
do
{
  int n;
  printf("\n\n Press 1) to push  \n Press 2) to dispaly\n Press 3) to pop \n  Press 4) to stop the program\n\n");
   scanf("%d",&task);
printf("\n\n");
 switch(task)
  {
    case 1:   printf("\nEnter the value you want to push in stack\n");
            scanf("%d",&n);   
            push(n);break;
    case 2:    display(top);break;
    case 3 :  pop(top);

  };
}while(task!=4);
}

//push
void push(int n)
{
    
       struct stack *p;
         p=(struct stack *)malloc(sizeof(struct stack ));
                 if(p==NULL)
                     {
                       printf("\nMemory allocation failed\n");
                         exit;
                       }
               p->data=n;
                      p->next=top;
                    top=p;
 }


//pop
void pop()
{
       
   if(top==0)
   printf("\nThe stack is empty\n");
   else
   {
       struct stack *temp;
     temp=top;
      top=top->next;
     printf("The value %d is being deleted",temp->data);
    free(temp);
     }
         
}




//display
void display(struct stack *top)
{
   if(top==0)
   printf("\nThe stack is empty\n");
 else
   {
           struct stack *temp;	 
             temp=top;
      while(temp!=0)
       {
             printf("%d ",temp->data);
               temp=temp->next;
        }     
   }
}

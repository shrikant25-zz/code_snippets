#include<stdio.h>
#include<stdlib.h>
#define MAX 30
//Declaring the structure
struct stack
{
  int data[MAX];
  int top;
};
//Initializing the functions
void intilialize(struct stack *ps);
void display(struct stack *ps);
void push(struct stack *ps,int n);
int pop(struct stack *ps);
int isempty(struct stack *ps);
int isfull(struct stack *ps);
void peek(struct stack *ps);
void reverse(struct stack *ps);
void insertAtBottom(struct stack *,int);
//main
int main()
{
   struct stack ps;
   int task=0;
do
{
  int n;
  printf("\n\n Press 1) to intialize \n Press 2) to push  \n Press 3) to dispaly\n Press 4) to pop \n Press 5) to peek \n Press 6 to reverse \n Press 7) to stop the program\n\n");
   scanf("%d",&task);
printf("\n\n");
 switch(task)
  {
    case 1:   intilialize(&ps);break;
    case 2:   printf("\nEnter the value you want to push in stack\n");
            scanf("%d",&n);
            push(&ps,n);break;
    case 3:    display(&ps);break;
    case 4 :  pop(&ps);break;
    case 5 :  peek(&ps);break;
    case 6 : reverse(&ps);

  };
}while(task!=7);
}
void intilialize(struct stack *ps)
{
 ps->top=-1;
}

//push
void push(struct stack *ps,int n)
{
   if(isfull(ps))
   printf("The stack is full");
   else
     {
       ++ps->top;
       ps->data[ps->top]=n;
     }
}

//pop
int pop(struct stack *ps)
{
   if(isempty(ps))
   printf("\nThe stack is empty\n");
   else
    // printf("The value %d is being deleted ",ps->data[ps->top]);
  return ps->data[ps->top--];
}


//isempty
int isempty(struct stack *ps)
{
    if(ps->top==-1)
    return 1;
return 0;
}

//isfull
int isfull(struct stack *ps)
{
  if(ps->top==(MAX-1))
        return 1;
return 0;
}

//display
void display(struct stack *ps)
{
   if(isempty(ps))
   printf("\nThe stack is empty\n");
 else
{
    int num=0;
   while((num) <= (ps->top))
    {
      printf("\nThe value at index position %d is %d \n",num,ps->data[num]);
     num++;
    }
}}
//peek
 void peek(struct stack *ps)
{
if(isempty(ps))
   printf("\nThe stack is empty\n");
else
printf("\nThe value at top postiton is %d\n",ps->data[ps->top]);
}


void reverse(struct stack *ps)
{
if(!isempty(ps))
{
        int n=pop(ps);
        reverse(ps);
        insertAtBottom(ps,n);
}
}
void insertAtBottom(struct stack *ps,int item)
{
    if (isempty(ps)) {
        push(ps,item);
    } else {

        /* Store the top most element of stack in top variable and
        recursively call insertAtBottom for rest of the stack */
        int n = pop(ps);
        insertAtBottom(ps,item);

        /* Once the item is inserted at the bottom, push the
        top element back to stack */
        push(ps,n);
    }
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 10


struct stack
{
 int a[MAX];
 int top;
};
void push(struct stack *,int);
int pop(struct stack *);
int isempty(struct stack *);
void display(struct stack *);
void reverse(struct stack *);
void insertatbottom(int,struct stack*);


void display(struct stack *p)
{
  int i=0; 
  i=p->top;
 while(i>=0)
  printf("%d ",p->a[i--]);
}


void reverse(struct stack *p)
{ 
	int n;
 if(!(isempty(p)))
  {
	n=pop(p);
	reverse(p);
	insertatbottom(n,p);
  }
}


void insertatbottom(int n,struct stack *p)
{
	int i;
 if(isempty(p))
	 push(p,n);
 else
 {
   i=pop(p);
   insertatbottom(n,p);
   push(p,i);
 }

}



int main()
{
	int option,data,n;
	struct stack s;
	s.top=-1;
	do
	{
	printf("\n1)Press 1 to push\n2)Press 2 to pop\n3)Press 3 to check if it is empty\n4)Press 4 to reverse the stack\n5)Press 5 to display\n6)Press 6 to exit\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1: printf("\nEnter the value to be pushed in stack\n");
			scanf("%d",&data);
			push(&s,data);break;
		case 2:if(isempty(&s))
			       printf("\nStack is Empty\n");
		       else
		       {
			      n=pop(&s);
			      printf("\nThe poped item is %d\n",n);
		       }break;
		 case 3:if(isempty(&s))
				printf("\nStack is empty\n");
			else
				printf("\nStack is not empty\n");break;
                 case 4 : if(isempty(&s))
			   printf("\nStack is Empty\n");
	                   else		   
			  reverse(&s);break;
	         case 5 : if(isempty(&s))
		           printf("\nStack is empty\n");
			   else
		           display(&s);break;
		case 6 : exit(1);break;
		default : printf("\nYOu have entered invalid option\n");
	};


		       
	}while(1);
	return 0;
}


void push(struct stack *s,int n)
{
 int i=0;
 if(s->top==MAX-1)
 printf("\nStack is full\n");
 else
    s->a[++s->top]=n;
}


int pop(struct stack *s)
{
return s->a[s->top--];
}


int isempty(struct stack *s)
{
 if(s->top==-1)
	return 1;
 return 0;
}

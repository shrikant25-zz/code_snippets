#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack
{
 int a[MAX];
 int top;
};

void push(struct stack *,int);
int pop(struct stack *);
int isempty(struct stack *);


int main()
{
	int option,n=0;
	int ch[MAX],c;
	struct stack s;
	s.top=-1;
	printf("\nHow many digits you want to enter\n");
	scanf("%d",&option);
	while(option > 0)
	{
	 printf("\nEnter the digit and press enter\n");
	 scanf("%d",&n);
	push(&s,n);
	option--;
	}
	 n=0;
	 printf("\nThe reversed number is\n");
	 while(!isempty(&s))
	   {
	      n=pop(&s);
	    printf("%d ",n);
	   }  
	 printf("\n\n");
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


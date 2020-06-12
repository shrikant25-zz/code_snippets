#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack
{
 char a[MAX];
 int top;
};

void push(struct stack *,char);
char pop(struct stack *);
int isempty(struct stack *);


int main()
{
	int option,n=0;
	char ch[MAX],c;
	struct stack s;
	s.top=-1;
	 printf("\nEnter the string to be pushed in stack\n");
	gets(ch);
	while(ch[n]!='\0')
	push(&s,ch[n++]);
	 n=0;
	 while(!isempty(&s))
	   {
	      c=pop(&s);
	      ch[n++]=c;
	   }
	 ch[n]='\0';
	 printf("\nThe revere string is: %s \n",ch);	       
	return 0;
}


void push(struct stack *s,char n)
{
 int i=0;
 if(s->top==MAX-1)
 printf("\nStack is full\n");
 else
    s->a[++s->top]=n;
}


char pop(struct stack *s)
{
return s->a[s->top--];
}

int isempty(struct stack *s)
{
 if(s->top==-1)
	return 1;
 return 0;
}


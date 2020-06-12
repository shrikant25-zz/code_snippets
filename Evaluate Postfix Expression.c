#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
struct stack
{ 
   int top;
   int data[MAX];
};
int pop(struct stack *);
void push(struct stack *,int);
int evaluate(struct stack *p,char[MAX]);
int pop(struct stack *p)
{
	if(p->top==-1)
	{
	  printf("\nStack is Empty\n");
	  return 0;
	}
	return(p->data[p->top--]);
}
void push(struct stack *p,int val)
{
	if(p->top==MAX-1)
	{
		printf("\nStack is Full\n");
		return;
	}
	p->data[++p->top]=val;
}
int evaluate(struct stack *p,char source[MAX])
{
	int i=0,value,a,b;
	while(source[i]!='\0')
	{
		if(isdigit(source[i]))
			push(p,(source[i]-'0'));
		else
		{
			b=pop(p);
			a=pop(p);
			switch(source[i])
			{
				case '+': value= a + b; break;
			        case '-': value= a - b; break;
			        case '%': value= a % b; break;
		                case '*': value= a * b; break;
			        case '/': value= a / b;    break;
			};
			push(p,value);
		}
		i++;
	}
	return(pop(p));
}
int main()
{

	struct stack p;
     char source[MAX];
     int value;
     p.top=-1;
printf("\nEnter the postfix expression\n");
scanf("%s",&source);
value=evaluate(&p,source);
printf("\n\%d\n",value);
}



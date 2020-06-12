#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
struct stack
{
 char data[MAX];
 int top;
};
char pop(struct stack *);
void push(struct stack *,char);
int prc(char);
void reverse(char *);
void prefix_e(struct stack *p);
char infix[20];
char prefix[20];
char temp[20];
int main()
{
 int option=0;
 int n=0;
 struct stack p;
 printf("\nEnter the infix expression\n");
 scanf("%s",&infix);
 reverse(infix);
 strcpy(infix,temp);
 p.top=-1;
 prefix_e(&p);
 reverse(prefix);
 strcpy(prefix,temp);
 printf("\nThe prefix expression is: \n");
 printf("%s",prefix);
 printf("\n\n");
}
void reverse(char *c)
{
 int n=0,i=0;
 n=strlen(c);
 n--;
 while(n>=0)
 {
  if(c[n]==')')
	  temp[i]='(';
  else if(c[n]=='(')
	  temp[i]=')';
  else
    temp[i]=c[n];
  i++;
  n--;
 }
temp[i]='\0';
}
void prefix_e(struct stack *p)
{
 int i=0,j=0;
 while(infix[i]!='\0')
 {
   if(infix[i]=='(')
    push(p,infix[i++]);
   else if(infix[i]==')')
    {
     while((p->data[p->top]!='(') && (p->top!=-1))
     {
      prefix[j++]=pop(p);
     }
     if(p->top==-1)
     {
      printf("\nIncorrect Expression found at ')'\n");
      exit(1);
     }
     pop(p);
     i++;
    }
  else if(isalnum(infix[i]))
   {
    prefix[j++]=infix[i++];
   }
  else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^' || infix[i]=='%')
   {
    while(  (prc(p->data[p->top]) >= prc(infix[i])) && (p->data[p->top]!='(') && (p->top!=-1))
      prefix[j++]=pop(p);
    push(p,infix[i++]);
   }
  else
   {
    printf("\nIncorrect Expression occurred due to unknown operator\n");
    exit(2);
   }
 }  
 while((p->top!=-1) && (p->data[p->top]!='('))
  prefix[j++]=pop(p);
 prefix[j]='\0';
}
void push(struct stack *p,char c)
{
 if(p->top==MAX-1)
  printf("\nSTACK is full\n");
 else
 p->data[++p->top]=c;
}
char pop(struct stack *p)
{
 if(p->top==-1)
	 printf("\nStack is Empty\n");
 else
    return (p->data[p->top--]);
}
int prc(char c)
{
  if(c=='^')
	  return 3;
  else if(c=='/' || c=='*' || c=='%')
	 return 2;
  else if(c=='+' || c=='-')
	  return 1;
}


#include<stdio.h>
#include<stdlib.h>


struct node
{
 int coefficient;
 int exponent;
 struct node *next;
};

struct node *create(struct node *);
void display(struct node *);
struct node *add(struct node *,struct node *,struct node*);
int main()
{
	int option=0,n=0;
	struct node *a=NULL,*b=NULL,*c=NULL;
	a=create(a);
	printf("\nThe first expression is\n");
	display(a);
	b=create(b);
	printf("\nThe second expresiion is\n");
	display(b);
	c=add(a,b,c);
        printf("\nThe addition of two expressions\n");
	display(c);
}


struct node * create(struct node *head)
{
 int n=0,c=0,e=0;
 struct node *new=NULL,*temp=NULL;
 printf("\nHow many nodes you want to create\n");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
	 new=(struct node *)malloc(sizeof(struct node));
	 printf("\nEnter the value of coefficient %d\n",i+1);
	 scanf("%d",&new->coefficient);
	 printf("\nEnter the value of exponent %d\n",i+1);
	 scanf("%d",&new->exponent);
	 new->next=NULL;
   if(head==NULL)
	   temp=head=new;
   else
   {
    temp->next=new;
    temp=new;
   }
 }
 return head;
}



void display(struct node *head)
{
 while(head!=NULL)
 {
  printf("%d",head->coefficient);
  printf("^");
  printf("%d ",head->exponent);
  head=head->next;
 }
 printf("\n\n");
}


	
struct node *add(struct node *a,struct node *b,struct node *c)
{
 struct node *new=NULL,*temp=NULL;
 while(a && b)
 {
   new=(struct node *)malloc(sizeof(struct node));
   new->next=NULL;
   if(a->exponent > b->exponent)
   {
    new->exponent=a->exponent;
    new->coefficient=a->coefficient;
    a=a->next;
   }
   else if(b->exponent > a->exponent)
   {
    new->exponent=b->exponent;
    new->coefficient=b->coefficient;
    b=b->next;
   }
   else 
   {
    new->exponent=a->exponent;
    new->coefficient=a->coefficient+b->coefficient;
    a=a->next;
    b=b->next;
   }
   if(c==NULL)
	   c=temp=new;
   else
   {
         temp->next=new;
	 temp=new;
   }
 }
 while(a)
 {
   new=(struct node *)malloc(sizeof(struct node));
   new->exponent=a->exponent;
   new->coefficient=a->coefficient;
   temp->next=new;
   temp=new;
   a=a->next;
 }
 while(b)
 {
  new=(struct node *)malloc(sizeof(struct node));
  new->exponent=b->exponent;
  new->coefficient=b->coefficient;
  temp->next=new;
  temp=new;
  b=b->next;
 }
 return c;
}

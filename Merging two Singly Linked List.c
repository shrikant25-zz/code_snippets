#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
 struct node *next;
};

struct node *create(struct node *head);
void display(struct node *head);
struct node *merge(struct node *n1,struct node *n2);

//main
int main()
{
  struct node *n1=0,*n2=0;
printf("\nCreating first list");
    n1=create(n1);
printf("\nFirst list\n");
display(n1);
printf("\nCreating second list");
    n2=create(n2);
printf("\nSecond list\n");
display(n2);
merge(n1,n2);
printf("\n\nThe merged list is :\n");
display(n1);
}


//create
struct node *create(struct node *head)	
{
   int n,i;
struct node *p,*last;

do
{
	printf("\n\nHow many nodes you want to create\n\n");
	scanf("%d",&n);
}while(n<=0);

for(i=1;i<=n;i++)
{
p=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the value in data field of node %d\n",i);
scanf("%d",&p->data);
p->next=0;

if(p==0)
{
  printf("\nMemory allocation failed\n");
  i--;
}
else
{
  if(head==0)
       last=head=p;
  else
{
    last->next=p;
    last=p;
}
}
}
return head;
}



//display
void display(struct node *head)
{
 printf("\n***The nodes are***\n");
  while(head!=0)
{
  printf("%d\t",head->data);
  head=head->next;
}
printf("\n");
}

struct node *merge(struct node *n1,struct node *n2)
{
     int temp;
    struct node *p=n1,*q=n2;
   while(p->next!=NULL)
    p=p->next;
   p->next=q;
   for(p=n1;p!=NULL;p=p->next)
     {
       for(q=p->next;q!=NULL;q=q->next)
        {
              if(p->data > q->data)
                {
           temp=p->data;
           q->data=p->data;
            q->data=temp;
                  }
        }
   }

}   
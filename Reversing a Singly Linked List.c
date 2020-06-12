#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
   struct node *next;
};
struct node *create(struct node *head);
void display(struct node *head);
struct node *reverse(struct node *head);
 int cnt;

int main()
{
struct node *head=NULL;
head=create(head);
display(head);
printf("\n\nThe linked list in reverse order is\n\n");
head=reverse(head);
display(head);
}
struct node *create(struct node *head)
{
   int n,i;
struct node *p,*last;

do
{
	printf("\nHow many nodes you want to create\n");
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
cnt++;
}
return head;
}


//display
void display(struct node *head)
{
 printf("\n***The nodes are***\n");
  while(head!=NULL)
{
  printf("%d\t",head->data);
  head=head->next;
}
printf("\n");
}

//reverse

struct node *reverse(struct node *head)
{
struct node *p=head,*q=0,*r=NULL;
while(p!=0)
{
   q=p->next;
   p->next=r;
   r=p;
   p=q;
}
return r;
}
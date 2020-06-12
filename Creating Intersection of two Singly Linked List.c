#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
 struct node *next;
};

struct node *create(struct node *head);
void display(struct node *head);
struct node *intersect(struct node *n1,struct node *n2,struct node *n3);

//main
int main()
{
  struct node *n1=0,*n2=0,*n3=0;
printf("\nCreating first list");
    n1=create(n1);
printf("\nFirst list\n");
display(n1);
printf("\nCreating second list");
    n2=create(n2);
printf("\nSecond list\n");
display(n2);
n3=intersect(n1,n2,n3);
printf("\n\nThe intersected list is :\n");
display(n3);
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

//intersect

struct node *intersect(struct node *p1,struct node *q1,struct node *r)
{
struct node *h=0,*l=0,*p=p1,*q=q1;
     
    int flag=0;
  while(q!=NULL)
   {  
        p=p1;
     while(p!=NULL)
     {
       if(q->data==p->data)
        {
          flag=1;
          break;
        }
       else
         p=p->next;
     }
     if(flag==1)
       {  

              r=(struct node *)malloc(sizeof(struct node));
             r->data=q->data;
             r->next=0;
           if(h==0)
            {
              l=h=r;
            }
           else
             { 
             l->next=r;
             l=r;
             }
      }
   flag=0;
     q=q->next;
   }
return h;
}
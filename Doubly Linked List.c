#include<stdio.h>
#include<stdlib.h>
int cnt;

//structure
struct node
{
 int data;
 struct node *next;
  struct node *prev;
};


//declartions
struct node *create(struct node *);
struct node *insert(struct node *,int position);
void display(struct node *head);
struct node *delete(struct node *,int position);
int search(struct node *,int pos);
struct node *del_val(struct node *head,int val);



//main
int main()
{
int pos=0,condition=0,val=0;
  struct node *head=0;
do
{
   printf("\n 1) Press 1 for create\n 2) Press 2 for display\n 3) Press 3 for insert\n 4) Press 4 for delete by position\n 5) Press 5 for search by value and get its position\n  6)Press 6 to stop the program\n\n\n");
   scanf("%d",&condition);


//switch
switch(condition)
{
 case 1:head=0;
 head=create(head);break; 
 case 2:  if(head==0)
          printf("\nLink is not present\n");
                else 
        display(head);break;
 case 3: do
              {
               printf("\nAt which position you want to enter new node\n");
               scanf("%d",&pos);
              }while(pos<=0 || pos>(cnt+1));

          head=insert(head,pos);break;
 case 4: do
           {
              printf("\nEnter position of node you want to delete\n");
               scanf("%d",&pos);
           }while(pos<=0 || pos>(cnt));
             head=delete(head,pos);break;
 case 5: 
            printf("\nEnter the value you want to search\n");
          scanf("%d",&val);
          pos=search(head,val);
        if(pos>0)
        printf("\nThe value was found at position %d\n",pos);
         else
          printf("\nThe value was not found \n");break;					


};
}while(condition!=6);
printf("\n\n\n***Program Ends***\n\n\n");
}





//create
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
   p->prev=last;
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
  while(head!=0)
{
  printf("%d\t",head->data);
  head=head->next;
}
}

//insert 
struct node *insert(struct node *head,int pos)
{
   int i;
  struct node *p,*q=head;


 p=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the value in data field of node\n");
scanf("%d",&p->data);
p->next=0;
p->prev=0;
//inserting at 1 pos
   if(pos==1)
  { 
    p->next=head;
       head->prev=p;
    head=p;
   cnt++;
  }
//appending
  else if(pos==(cnt+1))
  {
	while(q->next!=0)
q=q->next;
q->next=p;
p->prev=q;
 cnt++;
 
}
//inserting in between
else
  {
    q=head;
   for(i=1;i<pos-1;i++)
	q=q->next;
  p->next=q->next;
    q->next->prev=p;
   p->prev=q;
  q->next=p;
cnt++;

}
return head;
}

//delete
struct node *delete(struct node *head,int pos)
{
  struct node *p=0,*q=0;
p=head;
 int i=0;
//deleting 1 pos
   if(pos==1)
  { 
    head=head->next;
head->prev=0;
     free(p);
p=0;
cnt--;
}
//deleting last pos
  else if(pos==cnt)
{
   while(p->next!=0)
     p=p->next;
    p->prev->next=0;
      free(p);
      p=0;
     cnt--;
}
//deleting any pos in between
else
  {
    q=0;
   for(i=1;i<pos-1;i++)
p=p->next;
  q=p->next;
  p->next=q->next;
  q->next->prev=p;
 free(q);
q=0;
cnt--;
}
return head;
}


//search
int search(struct node *head,int value)
{
  int i=1;
    struct node *p;
p=head;
for(i=1;p!=0;i++)
 {
 if(value==p->data)
      return i;
else
p=p->next;
   }	
return 0;  
}

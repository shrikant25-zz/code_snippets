#include<stdio.h>
#include<stdlib.h>

struct tree
{
 int data;
 struct tree *left;
 struct tree *right;
};

struct tree *insert(struct tree *,int);
struct tree *inorder(struct tree *);
struct tree *postorder(struct tree *);
struct tree *preorder(struct tree *);
int search(struct tree * t,int);
int tncount(struct tree *);
int nlcount(struct tree *);
int lncount(struct tree *);
struct tree *mirror(struct tree *);

int main()
{
 int option=0,value=0,vsearch=0,n=0;
 struct tree *t=NULL;

 do{
     printf("\n 1)Press 1 to insert an element.\n 2)Press 2 to perform inorder traversal\n 3)Press 3 to perform preorder traversal\n 4)Press 4 to perform postorder traversal\n 5)Press search an element\n 6)Press 6 to count total nodes\n 7)Press 7 to count non-leaf nodes\n 8)Press 8 to count leaf nodes\n 9)Press 9 to perform mirroring of the tree\n 10)Press 10 to exit the program\n");
     scanf("%d",&option);
     switch(option)
     {
       case 1: printf("\nEnter the value you want to insert into the tree\n");
	       scanf("%d",&value);
	       t=insert(t,value);break;
       case 2: printf("\nThe inorder traversal of tree is\n");
	       inorder(t);break;
       case 3: printf("\nThe preorder traversal of tree is\n");
	       preorder(t);break;
       case 4: printf("\nThe postorder traversal of tree is\n");
	       postorder(t);break;
       case 5: printf("\nEnter the element you want to search in the treee\n");
	       scanf("%d",&vsearch);
	       if(search(t,vsearch))
		       printf("\nValue found in the tree\n");
	       else
		       printf("\nValue was not found in the tree\n");
	       break;
      case 6:  n=0;
	       n=tncount(t);
	       printf("\nThe total number of nodes in the tree are: %d\n",n);
	       break;
      case 7: n=0;
	     n=nlcount(t);
	     printf("\nThe total number of non-leaf nodes in the tree are: %d\n",n);
	     break;
      case 8: n=0;
	      n=lncount(t);
	      printf("\nThe total number of leaf nodes in the tree are: %d \n",n);
	      break;
      case 9: printf("\nTree before mirroring\n");
	      inorder(t);
	      printf("\nTree after mirroring\n");
	      mirror(t);
	      break;
      case 10: exit(0);break;
      default: printf("\nYou have entered wrong option\n");
     };
 }while(1);
}


struct tree *inorder(struct tree *t)
{
 if(t)
 {
  inorder(t->left);
  printf("%d ",t->data);
  inorder(t->right);
 }
}


struct tree *preorder(struct tree *t)
{
 if(t)
 {
  printf("%d ",t->data);
  preorder(t->left);
  preorder(t->right);
 }
}


struct tree *postorder(struct tree *t)
{
 if(t)
 {
  postorder(t->left);
  postorder(t->right);
  printf("%d ",t->data);
 }
}


struct tree *insert(struct tree *t,int n)
{
 struct tree *temp=NULL,*new=NULL,*temp1;
 temp=t;
 new=(struct tree *)malloc(sizeof(struct tree));
 new->data=n;
 new->left=NULL;
 new->right=NULL;
  if(t==NULL)
	 t=new;
  else
   {       
	 temp=t;
	 while(temp)
	 {
	   temp1=temp;
	   if(n < temp->data)
		  temp=temp->left;
	       else
		  temp=temp->right;
	 }
	 if(n < temp1->data)
                temp1->left=new;
	 else
		 temp1->right=new;
   }
	       		
return t;
}


int search(struct tree *t,int s)
{
 struct tree *temp=t;
 while(temp)
 {
  if(temp->data==s)
	  return 1;
  else if(temp->data > s)
   temp=temp->left;
   else
    temp=temp->right;
 }
  return 0;
}


int tncount(struct tree *t)
{
 struct tree *temp=t;
 int ans=0;
 if(temp==NULL)
	 return 0;
 ans=1+tncount(temp->left)+tncount(temp->right);
 return ans;
}


int lncount(struct tree *t)
{
 struct tree *temp=t;
 int ans=0;
 if(temp==NULL)
	 return 0;
 else if(temp->left==0 && temp->right==0)
	 return 1;
  ans=lncount(temp->left)+lncount(temp->right);
  return ans;
}


int nlcount(struct tree *t)
{
 struct tree *temp=t;
 int ans=0;
 if(temp==NULL)
	 return 0;
 else if(temp->right==NULL && temp->left==NULL)
	 return 0;
 ans=1+nlcount(temp->left)+nlcount(temp->right);
 return ans;
}


struct tree *mirror(struct tree *t)
{
 struct tree *temp=NULL;
 temp=t;
 if(temp)
 {
  temp=t->left;
  t->left=mirror(t->right);
  t->right=mirror(temp);
 }
 inorder(t);
}
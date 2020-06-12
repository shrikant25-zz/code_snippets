#include<stdio.h>
void insert(int n);
void display(int n);
int search(int ,int);
int a[100];

int main()
{
 int n=0,i=0;
 int val;
  printf("\nHow many elements you want to enter\n");
  scanf("%d",&n);
 insert(n);
  printf("\nThe array elements are\n");
  display(n);
  printf("\nEnter the value you want to search in array\n");
   scanf("%d",&val);
 if((i=search(n,val))==-1)
   printf("\nThe value is not found\n");
 else
  printf("\nThe value was found at index position %d\n",i);
}


void insert(int n)
{
 int i=0;
 printf("\nEnter the values\n");
   for(i=0;i<n;i++)
       scanf("%d",&a[i]);
}

 
void display(int n)
{
int i=0;
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
}


int search(int n,int val)
{
 int i=0,flag=0;
 for(i=0;i<n;i++)
 {
  if(a[i]==val)
  {
   flag=1;
    break;
  }
 }
 if(flag==1)
 return i;
 else
  return -1;
}


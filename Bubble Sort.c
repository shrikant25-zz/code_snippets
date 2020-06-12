#include<stdio.h>
void insert(int *,int);
void sort(int *,int);
void display(int *,int);


int main()
{
   int n;
  printf("\nHow many values you want to enter in array\n");
   scanf("%d",&n);
    int a[n];
   insert(a,n);
   printf("\nThe values of array are\n");
   display(a,n);
   sort(a,n);
   printf("\nThe values of array after sorting are\n");
   display(a,n);
}


void insert(int *a,int n)
{
  int i=0;
  printf("\nEnter the values of array\n");
   for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }
   printf("\n\n");
}


void display(int *a,int n)
{
   int i=0;
   for(i=0;i<n;i++)
   {
    printf("%d\t",a[i]);
   }
  printf("\n\n");
}


void sort(int *a,int n)
{
  int i=0,j=0,temp=0;
  for(i=0;i<n;i++)
   {
     for(j=0;j<n-i-1;j++)
       {
         if(a[j]>a[j+1])
          {
            temp=a[j];
            a[j]=a[j+1];
             a[j+1]=temp;
          }
       }
   }
printf("\n\n");
}
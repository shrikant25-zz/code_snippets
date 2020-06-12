#include<stdio.h>
void insert(int);
void sort(int,int);
void display(int);
int a[50];
int main()
{
   int n=0;
  printf("\nHow many values you want to enter in array\n");
   scanf("%d",&n); 
   insert(n);
   printf("\nThe values of array are\n");
   display(n);
   sort(0,n-1);
   printf("\nThe values of array after sorting are\n");
   display(n);
}
void insert(int n)
{
  int i=0;
  printf("\nEnter the values of array\n");
   for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }
   printf("\n\n");
} 
void display(int n)
{
   int i=0;
   for(i=0;i<n;i++)
   {
    printf("%d\t",a[i]);
   }
  printf("\n\n");
}
void sort(int low,int high)
{
  int i=0,j=0,pivot=0,temp=0;
  if(low<high)
   {
    pivot=a[low];
    i=low;
    j=high;
     while(i<j)
      {
       while(pivot>=a[i] && i<high)
        i++;
       while(pivot<a[j])
        j--;
        if(i<j)
         {
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
         }
      }
        a[low]=a[j];
        a[j]=pivot;
     sort(low,j-1);
     sort(j+1,high);

    }   
}
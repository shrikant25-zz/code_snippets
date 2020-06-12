#include<stdio.h>
void insert(int);
void divsort(int ,int);
void sort(int,int,int);
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
   divsort(0,n-1);
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
void divsort(int low,int high)
{
int mid=0;
if(low!=high)
 {
  mid=((low+high)/2);
  divsort(low,mid);
  divsort(mid+1,high);
  sort(low,mid,high);
 
 }
}

void sort(int low,int mid,int high)
{

  int i=0,j=0,k=0;
  int temp[50];
  i=low;
  k=low;
  j=mid+1;
  while( (i<=mid) && (j<=high) )
   {
     if(a[i]>=a[j])
        temp[k++]=a[j++];
     else
        temp[k++]=a[i++];
   }
  while(i<=mid)
     temp[k++]=a[i++];
  while(j<=high)
     temp[k++]=a[j++];
  for(i=low;i<=high;i++)
      a[i]=temp[i];
    
}
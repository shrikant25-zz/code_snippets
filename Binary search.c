#include<stdio.h>
#include<stdlib.h>


int binary_search(int);
int n=0;
int *a=0;
int main()
{
   int i=0,j=0,temp=0;
   printf("\nHow many elements you want to enter.\n");
   scanf("%d",&n);
   a=(int *)malloc(sizeof(int));
   printf("\nEnter the array elements.\n");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
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
   printf("\nThe sorted array is.\n");
   for(i=0;i<n;i++)
	   printf("%d\t",a[i]);
   printf("\nEnter the element to be searched.\n");
   scanf("%d",&j);
   printf("\nPerfrorming the binary search.\n");
    if(i=binary_search(j))
   printf("\nThe element was found at position %d(index position %d).\n",i,i-1);
   else
	   printf("\nElement was not found in the array.\n");
}




int binary_search(int key)
{
	int beg=0;
	int end=n-1;
	int mid=0;
  while(beg<=end)
  {
    mid=(beg+end)/2;
    if(a[mid]==key)
       	return mid+1;
    else if(key > a[mid])
	    beg=mid+1;
    else
        end=mid-1;
  }
	  return 0;
}

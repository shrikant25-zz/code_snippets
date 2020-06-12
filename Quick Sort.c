f(low<high)
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
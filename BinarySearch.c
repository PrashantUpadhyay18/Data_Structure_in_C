//binary search using recursion

#include <stdio.h>

//search function
int binary_search(int a[],int lb,int ub,int element)
{
   if(ub<lb)
    return -1;
   else
   {
       int mid=((lb + ub)/2); //mid value
       if(a[mid]==element)
       {
           return mid;
       }
       else
       {
            if(a[mid] < element)
                return binary_search(a,mid+1,ub,element);
            else
                return binary_search(a,lb,mid-1,element);
            
       }
   }
   
}

//main function
int main()
{
    int a[]={1,3,6,9,10};   //The array must be in a sorted order
    int lower_bound=0;  //first index
    int uper_bound=4;   //last index
    int value=binary_search(a,lower_bound,uper_bound,6);
    if(value>=0)
        printf("The element is at index : %d",value);
    else
        printf("The element is not present in array");
    return 0;
}
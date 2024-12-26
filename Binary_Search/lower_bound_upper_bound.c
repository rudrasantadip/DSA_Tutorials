
/*
The lower bound is the smallest index in the sorted array where a given target value 
can be placed (or exists), 
such that all elements at lower indices are strictly 
less than the target.
If the target exists in the array, it returns the index of the first occurrence of the target.
If the target does not exist, it returns the index where the target can be inserted to maintain the array's sorted order.
*/
#include <stdio.h>


int lower_bound(int arr[], int n,int target)
{
    int start = 0;
    int end = n-1;
    int mid;
    int ans=n;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]>=target)
        {
            ans=mid;
            end=mid-1;
        }
        else{
        start=mid+1;
        }
    }
    return ans;
}


int upper_bound(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid;
    int ans=n;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]>target)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {  
        start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int arr[] ={1, 3, 3, 5, 7};
    int arr2[]={1 ,2 ,8 ,8 ,8 ,8 ,12};

    printf("%d\n",lower_bound(arr2,sizeof(arr2)/sizeof(arr2[0]),8));
     printf("%d\n",upper_bound(arr2,sizeof(arr2)/sizeof(arr2[0]),8));
}
#include <stdio.h>


int binary_search(int arr[], int n,int target)
{
    int start = 0;
    int end = n-1;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]>target)
        {
            end=mid-1;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,5,7,9};
    printf("%d",binary_search(arr,sizeof(arr)/sizeof(arr[0]),17));
    return 0;
}
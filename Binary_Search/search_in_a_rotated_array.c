/*
Search in a rotated array- I with unique elements
*/


#include <stdio.h>

int search(int arr[],int n,int target)
{
    int low = 0,high = n-1,mid=0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]==target) return mid;

        // check if the left half is sorted
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=target && target<=arr[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        // or else if the right half is sorted
        else
        {
            if(arr[mid]<=target && target <=arr[high])
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;

}

int main()
{
    int arr[] = {7,8,9,1,2,3,4,5,6};
    int target = 1;

    printf("%d",search(arr,sizeof(arr)/sizeof(arr[0]),target));
    return 0;
}
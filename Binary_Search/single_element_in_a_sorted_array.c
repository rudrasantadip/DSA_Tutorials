/*
You are given a sorted array ‘arr’ of ‘n’ numbers
such that every number occurred twice in the array except one, which appears only once.
Return the number that appears once.
Example:
Input: 'arr' = [1,1,2,2,4,5,5]
[1 1 3 5 5] 

Output: 4
*/

#include <stdio.h>
int single_element(int arr[], int n)
{
    // edge cases
    // single element
    if(n==1)
    {
        return arr[0];
    }
    // first element -> 1 ,2,2,3,4
    if(arr[0]!=arr[1])
    {
        return arr[0];
    }
    // last element -> 1,1,2,2,3,3,4,4,5
    if(arr[n-1]!=arr[n-2])
    {
        return arr[n-1];
    }

    // primary logic
    int low=1,mid,high=arr[n-2];
    while(low<=high)
    {
        mid=(low+high)/2;
        // check for repetition [mid-1,mid,mid+1]
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])
        {
            return arr[mid];
        }
        // check if we are in the left half
        if( 
            ((mid%2)==1 && arr[mid]==arr[mid-1]) ||
            ((mid%2)==0 && arr[mid]==arr[mid+1])
            )
        {
            // trim the left half
            low = mid+1;
        }
        // we are in the right half
        else{
            // trim the right half
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
int arr[] = {1,1,2,2,4,5,5};
printf("%d",single_element(arr,sizeof(arr)/sizeof(arr[0])));    
return 0;
}
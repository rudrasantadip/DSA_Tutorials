/*
You are given an array 'arr' of size 'n' having unique elements that has been sorted in ascending order and rotated between 1 and 'n' times which is unknown.
The rotation involves shifting every element to the right, 
with the last element moving to the first position. 
For example, if 'arr' = [1, 2, 3, 4] was rotated one time, it would become [4, 1, 2, 3].

Your task is to find the minimum number in this array.
Note :
All the elements in the array are distinct.
Example :
Input: arr = [3,4,5,1,2]

Output: 1

*/
#include <stdio.h>
#include <limits.h>

int min_element(int arr[], int n)
{
    int low=0,high=n-1;
    int mid;
    int minimum=INT_MAX;
    while(low<=high)
    {
        mid = (low+high)/2;
        // check if the left side is sorted
        if(arr[low]<=arr[mid])
        {
            minimum = (minimum<arr[low])? minimum : arr[low];
            low=mid+1;
        }
        else
        {
            minimum = (minimum<arr[mid])? minimum : arr[mid];
            high=mid-1; 
        }
    }
    return minimum;
}



int main()
{
    int arr[] = {3,4,5,1,2};
    printf("%d",min_element(arr,sizeof(arr)/sizeof(arr[0])));
    return 0;
}
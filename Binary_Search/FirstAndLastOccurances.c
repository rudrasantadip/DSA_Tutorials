/*
 * Given a sorted array arr with possibly some duplicates, the task is to find the first and last occurrences
 * of an element x in the given array.
    Note: If the number x is not found in the array then return both the indices as -1.
 * 
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
   printf("%d\n",upper_bound(arr2,sizeof(arr2)/sizeof(arr2[0]),8)-1);

   return 0;
}
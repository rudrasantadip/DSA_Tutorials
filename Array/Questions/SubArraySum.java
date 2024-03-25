/*
 * Given an unsorted array A of size N that contains only positive integers,
 *  find a continuous sub-array that adds to a given number S 
 * and return the left and right index(1-based indexing) of that subarray.
In case of multiple subarrays, return the subarray indexes 
which come first on moving from left to right.
Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.
 */

import java.util.ArrayList;

public class SubArraySum
{
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) 
    {
      int i=0,j=1,sum=0;
      while (i<n)
      {
          sum=sum+arr[i];  
      }  
       return null;
    }

    public static void main(String[] args)
    {
        int arr[]={1,2,3,7,5};
        subarraySum(arr, 5, 12);
    }    
}

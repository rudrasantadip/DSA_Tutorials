
/*
 * Given an array arr of non-negative numbers. 
 * The task is to find the first equilibrium point in an array. 
 * The equilibrium point in an array is an index (or position) 
 * such that the sum of all elements before that index is the same as the sum of elements after it.
 */

public class EquilibriumPoint 
{
    static int rangeSum(int arr[],int start, int end)
    {
        int sum=0;
        for(int i=start;i<=end;i++)
        {
            sum+=arr[i];
        }
        return sum;
    }
    public static void main(String[] args) {
        int arr[]={1, 2, 3};

        for(int i=0;i<arr.length;i++)
        {
            if(rangeSum(arr, 0, i)==rangeSum(arr, i, arr.length-1))
            {
                System.out.println(i+1);
                break;
            }
        }
       
    }
}

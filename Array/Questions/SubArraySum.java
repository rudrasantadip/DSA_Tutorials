/*
 * Indexes of Subarray Sum
 * Given an array arr[] containing only non-negative integers, your task is to
 * find a continuous subarray (a contiguous sequence of elements) whose sum
 * equals a specified value target. You need to return the 1-based indices of
 * the leftmost and rightmost elements of this subarray. You need to find the
 * first subarray whose sum is equal to the target.
 * 
 * Note: If no such array is possible then, return [-1].
 */

public class SubArraySum
 {
    public static void main(String[] args) {
         // Record the start time
         long startTime = System.nanoTime();




         // Your program logic here
        int arr[]= {1, 2, 3, 7, 5};
        int start = 0,end =0, n=arr.length;
        int currSum=0;
        int target=0;
        for(end = 0;end<n;end++)
        {
            currSum+=arr[end];
            while(currSum>target && start<=end)
            {
                currSum-=arr[start];
                start++;
            }

            if(currSum==target)
            {
                break;
            }
        }
        System.out.println(start+1);
        System.out.println(end+1);



         // Record the end time
         long endTime = System.nanoTime();

         // Calculate the elapsed time in seconds
         double durationInSeconds = (endTime - startTime) / 1_000_000_000.0;
 
         System.out.println("Execution Time: " + durationInSeconds + " seconds");
     }
    }
 
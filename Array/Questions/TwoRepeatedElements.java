import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TwoRepeatedElements {
    /*
     * You are given an integer n and an integer array arr of size n+2. All elements
     * of the array are in the range from 1 to n. Also, all elements occur once
     * except two numbers which occur twice. Find the two repeating numbers.
     * Note: Return the numbers in their order of appearing twice. So, if x and y
     * are repeating numbers, and x's second appearance comes before the second
     * appearance of y, then the order should be (x, y).
     */

     public static void main(String[] args) {

        long startTime = System.nanoTime();
        int arr[]={1, 2, 1, 3, 4, 3};
        int []soln=new int[2];
        int index=0;
        int n=4;

        for(int i=0;i<n+2;i++)
        {
            int absValue=Math.abs(arr[i]);
            if(arr[absValue-1]<0)
            {
                soln[index++]=arr[i];
            }
            else{
                arr[absValue-1]=-arr[absValue-1];
            }
            if(index==2)
            {
                break;
            }
        }

        System.out.println(Arrays.toString(soln));
        

         // Record the end time
         long endTime = System.nanoTime();


         // Calculate the elapsed time in seconds
         double durationInSeconds = (endTime - startTime) / 1_000_000_000.0;
         System.out.println("Execution Time: " + durationInSeconds + " seconds");
     }
}

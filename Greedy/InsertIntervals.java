import java.util.ArrayList;
import java.util.Arrays;


public class InsertIntervals {
    /*
     * You are given an array of non-overlapping intervals intervals where
     * intervals[i] = [starti, endi] represent the start and the end of the ith
     * interval and intervals is sorted in ascending order by starti. You are also
     * given an interval newInterval = [start, end] that represents the start and
     * end of another interval.
     * 
     * Insert newInterval into intervals such that intervals is still sorted in
     * ascending order by starti and intervals still does not have any overlapping
     * intervals (merge overlapping intervals if necessary).
     * 
     * Return intervals after the insertion.
     * 
     * Note that you don't need to modify intervals in-place. You can make a new
     * array and return it.
     */
    public static void main(String[] args) {
       ArrayList<int[]> soln = new ArrayList<>();
        int [][] intervals = {{1,2},{3,4},{6,7},{8,10},{12,16}};
        int newInterval[] = {5,8};

        //finding the left non converging intervals
        int i=0;
        while(
        i<intervals.length //traverse the entire length of the array 
        && 
        /*
         * a given interval does not converge if its ending time is lesser than
         * the starting time of the newinterval
         */
        intervals[i][1]<newInterval[0]
        )
        {
            soln.add(intervals[i]);
            i++;
        }

        //finding the convering intervals
        while(i<intervals.length 
        &&
        /*
         * An interval is convering if its starting time
         * is starting time is less than the ending time 
         * of the new interval
         */
        intervals[i][0]<newInterval[1] 
        )
        {
            newInterval[0]=Math.min(newInterval[0], intervals[i][0]); //compare the minimum between the newinterval and the current interval for starting point
            newInterval[1]=Math.max(newInterval[1], intervals[i][1]); //compare the maximum between the newinterval and current interval for ending point
            i++;
        }

        soln.add(newInterval); // add the new interval

        while (i<intervals.length) 
        {
            soln.add(intervals[i]);
            i++;    
        }

        soln.forEach(s ->{
            System.out.println(Arrays.toString(s));
        });
    }
}

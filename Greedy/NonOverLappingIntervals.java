import java.util.Arrays;
import java.util.Comparator;

public class NonOverLappingIntervals {

    /*
     *Given an array of intervals intervals where intervals[i] = [starti, endi],
     * return the minimum number of intervals you need to remove to make the rest of
     * the intervals non-overlapping.
     */

    public static void main(String[] args) 
    {
        int [][] intervals = {{1,2},{2,3},{3,4},{1,3}};

        /*
        *Sorting the array 
        */
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] row1, int[] row2) {
                // Change the index (columnIndex) to sort by a different column
                return Integer.compare(row1[1], row2[1]);
            }
        });

        int currentEnd=intervals[0][1],count=1;

        for(int i=1;i<intervals.length;i++)
        {
            if(intervals[i][0]>=currentEnd)
            {
                count++;
                currentEnd=intervals[i][1];
            }
        }

        System.out.println(intervals.length-count);
    }
}
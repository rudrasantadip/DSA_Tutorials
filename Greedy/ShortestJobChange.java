import java.util.Arrays;

public class ShortestJobChange {
    /*
     * Shortest Job First (sjf) -> scheduling policy 
     * that selects the waiting process with
     * the smallest execution time.
     */
    
    public static void main(String[] args) {
        int [] jobs = {4,3,7,1,2};

        int timer = 0;
        int waitTime = 0;

        Arrays.sort(jobs);
        // 1 2 3 4 7

        for(Integer job : jobs)
        {
            waitTime+=timer; 
            timer+=job;
        }

        System.out.println(timer);
        System.out.println(waitTime);
    }
}

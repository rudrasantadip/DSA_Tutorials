import java.util.Arrays;
import java.util.Comparator;

class Job
{
    public Integer id;
    public Integer deadLine;
    public Integer profit;

    public Job(Integer id, Integer deadLine, Integer profit)
    {
        this.id=id;
        this.deadLine=deadLine;
        this.profit=profit;
    }

    @Override
    public String toString() {
        return "Job [id=" + id + ", deadLine=" + deadLine + ", profit=" + profit + "]";
    }

    
    public static void printJobs(Job[] jobs)
    {
        for(Job j : jobs)
        {
            System.out.println(j);
        }
    }
}

class JobComparator implements Comparator<Job>
{

    @Override
    public int compare(Job o1, Job o2) {
       return Integer.compare(o2.profit, o1.profit);
    }
    
}


public class JobSequencing {

    /*
     * Given a set of N jobs where each jobi has a deadline and profit associated
     * with it.
     * 
     * Each job takes 1 unit of time to complete and only one job can be scheduled
     * at a time. We earn the profit associated with job if and only if the job is
     * completed by its deadline.
     * 
     * Find the number of jobs done and the maximum profit.
     * 
     * Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated
     * with that Job. Deadline of the job is the time before which job needs to be
     * completed to earn the profit.
     */

    static void function(Job [] jobs)
    {
        //sort the josbs array according to decreasing order of profit
        Arrays.sort(jobs,(j1,j2)->Integer.compare(j2.profit, j1.profit)); 

        //create a hash array, to store the job id for a given dead line
        int hash[] = new int[jobs.length+1];

        //variables for calculating total profit, counting the number of jobs
        int totalProfit=0,count=0,maxDeadLine=-1;

        for(int i=0;i<jobs.length;i++)
        {
           //setting -1 at only those indexes, where a job is to be performed
           maxDeadLine=Math.max(maxDeadLine, jobs[i].deadLine); 
           hash[maxDeadLine]=-1;
        }


        for(int i=0;i<jobs.length;i++)
        {
            for(int j=jobs[i].deadLine;j>0;j--)
            {
                if(hash[j]==-1)
                {
                    count++;
                    hash[j]=jobs[i].id;
                    totalProfit+=jobs[i].profit;
                    break;
                }
            }
        }


        System.out.println("Total Profit: "+totalProfit);
        System.out.println("No of jobs done: "+count);
    }

    public static void main(String[] args)
    {
        // Jobs Array
        Job [] jobs = {
            new Job(1, 4, 20),
            new Job(2, 1, 10),
            new Job(3, 1, 40),
            new Job(4, 1, 30),
        };


       
        function(jobs);
    }
}
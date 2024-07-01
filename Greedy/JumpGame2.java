public class JumpGame2 {

    /*
     * You are given a 0-indexed array of integers nums of length n. You are
     * initially positioned at nums[0].
     * 
     * Each element nums[i] represents the maximum length of a forward jump from
     * index i. In other words, if you are at nums[i], you can jump to any nums[i +
     * j] where:
     * 
     * 0 <= j <= nums[i] and
     * i + j < n
     * Return the minimum number of jumps to reach nums[n - 1]. The test cases are
     * generated such that you can reach nums[n - 1].
     */

     public static int isJumpPossibleRec(int []jumps,int index, int jump)
     {
        int min = Integer.MAX_VALUE;
        if(index>=jumps.length-1)
        {
            return jump;
        }
        for(int i=1;i<=jumps[index];i++)
        {
            min = Math.min(min, isJumpPossibleRec(jumps, index+i, jump+1));
        }
        return min;
    }


    public static Integer isJumpPossible(int []arr)
    {
        int jumps=0, l=0,r=0;

        while (r<=arr.length) 
        {
            int farthest = 0;
            for(int i=l;i<=r;i++)
            {
                farthest = Math.max(farthest, i+arr[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;    
        }
        return jumps;
    }

    public static void main(String[] args) {
        int jumps[] ={2,3,1,1,4};

        System.out.println(isJumpPossibleRec(jumps,0,0));

        System.out.println(isJumpPossible(jumps));
    }
}

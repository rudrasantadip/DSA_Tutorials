
/*
*You are given an integer array nums. You are initially positioned at the array's first index, 
*and each element in the array represents your maximum jump length at that position.
 Return true if you can reach the last index, or false otherwise.
 */

public class JumpGame1 {

    public static Boolean canJump(int [] jumps)
    {
        int maxIndex = 0;
        for(int i=0;i<jumps.length;i++)
        {
            if(i>maxIndex)
            {
                return false;
            }
            maxIndex = Math.max(maxIndex, i+jumps[i]);
        }
        return true;
    }
    public static void main(String[] args) {
        int jumps[] = {1,2,3,1,1,0,2,5};

        System.out.println(
            canJump(jumps)
        );

    }
}

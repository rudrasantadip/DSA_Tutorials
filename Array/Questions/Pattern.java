/*
Input: 
N = 16
Output: 
16 11 6 1 -4 1 6 11 16
Explaination: 
The value decreases until it is greater than 0. After that it increases and stops when it becomes 16 again.
Without using loop
*/

import java.util.ArrayList;
import java.util.List;

class Pattern {

    void f1(int n, List<Integer> integers) 
    {
        integers.add(n);
        if (n <= 0) {
            return ;
        }
        f1(n - 5,integers);
    }

    void f2(int low, int high,List<Integer> integers) 
    {
        integers.add(low);
        if (low >= high) {
            return ;
        }
        f2(low + 5, high,integers);
    }

    public List<Integer> printPattern(int n) 
    {
        List<Integer> data = new ArrayList<>();
        if(n==0)
        {
            data.add(n);
            return data;
        }
        else
        {
        f1(n, data);
        int item =data.get(data.size()-1);
        data.remove(data.size()-1);
        f2(item, n,data);
        return data;
        }

      
    }

    public static void main(String args[]) {
        Pattern p = new Pattern();
       List<Integer> integers= p.printPattern(16);
       System.out.println(integers);
    }
}
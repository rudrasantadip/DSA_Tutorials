/**
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
 */



public class LemonadeChange {

    public static Boolean change(int [] bill)
    {
        int five=0,ten=0,twenty=0; //possible bills

        for(int i=0;i<bill.length;i++)
        {
            if(bill[i]==5)
            {
                five++;
            }
            else if(bill[i]==10)
            {
                if(five>0)
                {
                    ten++;
                    five--;
                }
                else{
                    return false;
                }
            }
            else if(bill[i]==20)
            {
                if(five>0 && 10 >0)
                {
                    twenty++;
                    ten--;
                    five--;
                }
                else if(five>=3)
                {
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
            int bill1 [] ={5,5,5,10,20};
            int bill2 [] = {5,5,10,10,20};


            System.out.println(change(bill1));
            System.out.println(change(bill2));

    }   
}

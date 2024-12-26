#include <stdio.h>

/*
A chocolate factory is packing chocolates into the packets
The chocolate packets here represent an array of n numbers
of integer values. The task is to find the empty packets(0)
of chocolate and push ut into the end of conveoyor belt array

example : [5,9,0,1,2,0,3,4,0]
output : [5,9,1,2,3,4,0,0,0]
*/


int main()
{
    int input[] = {5,9,0,1,2,0,3,4,0};
    chocolate(input,sizeof(input)/sizeof(input[0]));

}
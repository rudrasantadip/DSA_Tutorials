#include <stdio.h>

int main()
{

    /*
    sizeof is an operator available in c, 
    which returns the total memory occupied by a
    variable or a structure
    SYNTAX : sizeof(<variable-name>)
    */
    int a=2;
    printf("Size of an integer is: %d\n",sizeof(a));

    float f = 2.32;
    printf("Size of floating point number is: %d\n",sizeof(f));

    double d = 2.3265;
    printf("Size of double number is: %d\n",sizeof(d));

    char c = 'A';
    printf("Size of a character is: %d\n",sizeof(c));

    /*
    IN CASE OF AN ARRAY WHAT IT DOES TO COUNT THE TOTAL SPACE?
    NUMBER OF ELEMENTS * SIZE OF EACH ELEMENT OF THE ARRAY
     */
    int arr[] = {3,2,1};
    printf("size of the array: %d",sizeof(arr));
    /*
    The above is an integer array
    hence size of each element is 4
    and total number of elements is 3
    hence 4*3=12
    */
   return 0;

}
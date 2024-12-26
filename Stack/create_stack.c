/*
Create a stack using array
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // maximum possible size
typedef struct Stack
{
    int arr[MAX];    // to store the data
    int currentSize; // current size of the stack
    int top;         // variable to point at the top
} Stack;

//function to initialize stack
Stack *stack_init(int currentSize)
{
    // stack initialization
    Stack *s = (Stack *)malloc(sizeof(Stack)); // memory chunk is assigned;
    s->top = -1;
    return s;
}

int isEmpty(Stack *s)
{
    return s->top==-1;
}

//function to push

int push(Stack *s,int data)
{

    //if the stack is empty
    if(s==NULL)
    {
        printf("Stack is empty");
        return -1;
    }
    //step 1 increment the top by 1
    s->top++;
    //step 2 , insert the data in the stack
    s->arr[s->top]=data;
    return s->arr[s->top];
}


int pop(Stack *s)
{
    int r = s->arr[s->top];
    s->top--;
    return r;
}

int main()
{
    Stack * s = stack_init(5);
    
    int result = push(s,10);
    printf("%d",isEmpty(s));
    
    // result = push(s,20);
    // result = push(s,30);

    // printf("%d",pop(s));
    return 0;
}
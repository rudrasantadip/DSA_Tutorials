#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *array;
    int front, rear, size;
    unsigned capacity;
} Queue;

Queue *createQ(unsigned capacity)
{
    Queue *newQ = (Queue *)malloc(sizeof(Queue));
    newQ->capacity = capacity;
    newQ->array = (int *)malloc(sizeof(int) * capacity);
    newQ->front = 0;
    newQ->rear = capacity - 1;
    newQ->size = 0;
    return newQ;
}

int isFull(Queue *Q)
{
    if (Q->capacity == Q->size)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int isEmpty(Queue *Q)
{
    if (Q->size == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void enqueue(Queue *queue, int data)
{
    if (isFull(queue) == -1)
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = data;
        queue->size++;
    }
    else
    {
        printf("queue is full");
    }
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue) == -1)
    {
        int item = queue->array[queue->front];
        queue->front = queue->front + 1;
        // queue->size--;
    }
    else
    {
        printf("queue is empty");
    }
}

void printQ(Queue *queue)
{
    int i;
    for (i = queue->front; i < queue->size; i++)
    {
        printf("%d  ", queue->array[i]);
    }
    printf("\n");
}

int main()
{

    Queue *queue = createQ(20);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    printQ(queue);
    dequeue(queue);
    printQ(queue);

    return 0;
}
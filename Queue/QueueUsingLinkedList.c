#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

QNode *createNode(int data)
{
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
typedef struct  Queue
{
    QNode *front;
    QNode *rear;
}Queue;

Queue *createQueue()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front=NULL;
    queue->rear=NULL;
}

void enqueue(Queue *queue, int data)
{
    QNode *newNode = createNode(data);
    if(queue->front==NULL && queue->rear==NULL)
    {
        queue->front=queue->rear=newNode;
    }
    else
    {
        queue->rear->next=newNode;
        queue->rear=newNode;
    }
}

void dequeue(Queue *queue)
{
    if(queue->front==NULL&&queue->rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        QNode *toDelete = queue->front;
        queue->front=queue->front->next;
        free(toDelete);
    }
}

void printQ(Queue *queue)
{
    QNode *travel = queue->front;
    while (travel!=queue->rear->next)
    {
        printf("%d ",travel->data);
        travel=travel->next;
    }
    printf("\n");
    
}

int main()
{
    Queue *queue =createQueue();
    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    enqueue(queue,5);
    printQ(queue);
    dequeue(queue);
    printQ(queue);
    return 0;
}
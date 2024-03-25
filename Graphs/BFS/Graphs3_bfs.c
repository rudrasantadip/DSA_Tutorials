#include <stdio.h>
#include <stdlib.h>

// UNWEIGHTED GRAPH DATA STRUCTURE IMPLEMENTATION USING AN ADJACENCY LIST
//  TIME COMPLEXITY O(2N)

// Structure of a single node
typedef struct NODE
{
    int data;
    struct NODE *next;
} Node;

// Structure of a linked list
typedef struct ll
{
    Node *head;
} LinkedList;

typedef struct Q
{
    Node *front;
    Node *rear;
} Queue;

// Structre of a graph...
typedef struct graph
{
    LinkedList **array; // creating an array to store linked lists...(i.e to store type : *LinkedList)
    int V;              // no of vertex....
} Graph;

// initializing a node...
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// initializing the queue
Queue *init_Queue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}


// Function to add an element to the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = queue->front->data;
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

void printQ(Queue *queue)
{
       if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        Node* temp = queue->front;
        printf("Queue elements are:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// initializing a linkedlist...
LinkedList *init_LinkedList()
{
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList)); // allocating memory to the linked list..
    ll->head = NULL;
    return ll;
}

// Adding to the linked list...
void add_to_list(LinkedList **ll, int data)
{
    Node *newNode = createNode(data); // creating a node..
    if ((*ll)->head == NULL)
    {
        (*ll)->head = newNode; // if the head is empty adding the node
    }
    else
    {
        Node *temp =(*ll)->head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }

}

// Printing a linked list...
void printList(LinkedList *ll)
{
    Node *temp = ll->head;
    if (temp == NULL)
    {
        printf("\n");
        return;
    }
    printf("{");

    while (temp->next != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("}");
    printf("\n");
}

// Initializing a graph...
Graph *init_Graph(int V)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;
    g->array = (LinkedList **)malloc(sizeof(LinkedList *) * (g->V + 1));
    for (int i = 0; i < g->V + 1; i++)
    {
        g->array[i] = init_LinkedList();
    }
    return g;
}

// Printing a graph...
void printGraph(Graph *g)
{
    int i;

    for (i = 1; i <= g->V; i++)
    {
        printf("V[%d] -> ", i);
        printList(g->array[i]);
    }
}

// adding an edge to a graph...
void addEdge(Graph **g, int source, int destination)
{
    if (source > (*g)->V || destination > (*g)->V)
    {
        printf("Max Vertices exceeded at [%d  %d]\n", source, destination);

        return;
    }
    // edge 1--->2 .. [sourceVertex -> destinationVertex]
    add_to_list(&(*g)->array[source], destination);

    // Since Graph is unweighted ... viceversa
    add_to_list(&(*g)->array[destination], source);
}

LinkedList *bfs(Graph *g)
{
    int i;
    LinkedList *solution = init_LinkedList();
    LinkedList *neighbours = init_LinkedList();
    int visited[g->V];
    Queue *q = init_Queue();


    for (i = 0; i < g->V; i++)
    {
        visited[i] = 0;
    }

    i=1;
    enqueue(q,i);
    visited[i]=1;
    while (isEmpty(q)==0)
    {
        int node = dequeue(q);
        if(node!=-1)
        {
        add_to_list(&solution,node);
        neighbours = g->array[node];
        //Storing the ll neighbours head in a temporary variable
        Node *temp = neighbours->head;
        while (temp!=NULL)
        {
            if(visited[temp->data]==0)
            {
                visited[temp->data]=1;
                enqueue(q,temp->data);
            }
            temp=temp->next;
        }
        }
        
    }
    return solution;
}

int main()
{
    Graph *g = init_Graph(9); // initializing a graph...

    // Adding edges to the graph...

    addEdge(&g, 1, 2);
    addEdge(&g, 1, 6);
    addEdge(&g, 2, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 6, 7);
    addEdge(&g, 6, 8);
    addEdge(&g, 4, 5);
    addEdge(&g, 7, 5);
    // printGraph(g);

    LinkedList *bfsResult = bfs(g);
    printList(bfsResult);
}
#include <stdio.h>
#include <stdlib.h>

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

// Structre of a graph...
typedef struct graph
{
    LinkedList **array; // creating an array to store linked lists...(i.e to store type : *LinkedList)
    int V; // no of vertex....
} Graph;

// initializing a node...
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}

// initializing a linkedlist...
LinkedList *init_LinkedList()
{
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList)); // allocating memory to the linked list..
    ll->head = NULL;
    return ll;
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
        // Adding the node at the beginning of the list..
        newNode->next = (*ll)->head; // copying the current address of the node
        (*ll)->head = newNode; // setting the head's address to the new node
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
    if(source>(*g)->V || destination>(*g)->V)
    {
        printf("Max Vertices exceeded at [%d  %d]\n",source,destination);

        return;
    }
    // edge 1--->2 .. [sourceVertex -> destinationVertex]
    add_to_list(&(*g)->array[source], destination);

    // Since Graph is unweighted ... viceversa
    add_to_list(&(*g)->array[destination], source);
}

int main()
{
    Graph *g = init_Graph(5); // initializing a graph...

// Adding edges to the graph...
    addEdge(&g, 1, 2);
    addEdge(&g, 3, 4);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 3);
    addEdge(&g, 1, 5);

    printGraph(g);

    return 0;
}
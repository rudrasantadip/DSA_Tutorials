#include <stdio.h>
#include <stdlib.h>


//Structure of a single node
typedef struct NODE
{
    int data;
    struct NODE *next;
}Node;

//Structure of a linked list
typedef struct ll
{
    Node *head;
}LinkedList;

// Structre of a graph...
typedef  struct  graph
{
    LinkedList **array;
    int V;
}Graph;



// initializing a node...
Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
}


// initializing a linkedlist...
LinkedList *init_LinkedList()
{
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    ll->head=NULL;
    return ll;
}

//Initializing a graph...
Graph *init_Graph(int V)
{
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->V=V;
    g->array = (LinkedList **)malloc(sizeof(LinkedList*)*g->V);
     for (int i = 0; i < g->V; i++) {
        g->array[i] = init_LinkedList();
    }
    return g;
}

// Adding to the linked list...
void add_to_list(LinkedList **ll, int data)
{
    Node *newNode =createNode(data); 
    if((*ll)->head==NULL)
    {
        (*ll)->head = newNode;
    }
    else
    {
        newNode->next = (*ll)->head;
        (*ll)->head = newNode;
    }
}

//Printing a linked list...
void printList(LinkedList *ll)
{
    Node *temp = ll->head;
    if(temp==NULL)
    {
        printf("\n");
        return;
    }
    printf("{");

    while (temp->next!=NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
    printf("}");
    printf("\n");
}

//Printing a graph...
void printGraph(Graph *g)
{
    int i;

    for(i=0;i<g->V;i++)
    {
        printf("V[%d] -> ",i);
        printList(g->array[i]);
    }
}

//adding an edge to a graph...
void addEdge(Graph **g, int source, int destination)
{
        add_to_list(&(*g)->array[source],destination);
        add_to_list(&(*g)->array[destination],source);
}

int main()
{
    Graph *g = init_Graph(5);
   
   addEdge(&g,1,2);
   addEdge(&g,3,4);
   addEdge(&g,1,3);
   addEdge(&g,2,3);

    // add_to_list(&g->array[0],1);
    // add_to_list(&g->array[0],3);
    // add_to_list(&g->array[0],3);
    // add_to_list(&g->array[0],4);

    // add_to_list(&g->array[1],2);
    // add_to_list(&g->array[1],3);
    // add_to_list(&g->array[1],4);
    // add_to_list(&g->array[1],4);
    


    printGraph(g);
  

    
    return 0;
}
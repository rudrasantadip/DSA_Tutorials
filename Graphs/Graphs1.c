#include <stdio.h>
#include <stdlib.h>

//UNWEIGHTED GRAPH WITH ADJACENCY MATRIX
// Time Complexity : O(N X N)
typedef struct graph
{
    int **adj; // adjacency matrix..
    int no_edges; // m
    int no_nodes; // n
}Graph;

void graph_init(Graph **g, int n);
void graph_details(Graph *g);
void addEdge (Graph *g, int sourceI, int destI);


//void  graph init (graph, number of nodes, number of edges)
void graph_init(Graph **g, int n)
{
    int i;
    *g = (Graph*)malloc(sizeof(Graph)); // allocating memory to the graph structure
    (*g)->no_nodes=n; // setting the number of nodes
    (*g)->no_edges=0; // setting the number of edges

    (*g)->adj= (int **)malloc(sizeof(int)*(n+1)); // initializing the adjacency matrix
    for(i=0;i<n+1;i++)
    {
        (*g)->adj[i]=(int *)malloc(sizeof(int)*(n+1)); // allocating memory at each index, to create the matrix
    }

    for(i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0)
            {
             (*g)->adj[i][j]=j;   
            }
            else if(j==0)
            {
             (*g)->adj[i][j]=i;   
            }
            else
            {
            (*g)->adj[i][j]=0; // assigning 0 to each node index...
            }
        }
    }
}


void print_graph(Graph *g)
{
     for(int i=0;i<g->no_nodes+1;i++)
    {
        for(int j=0;j<(g)->no_nodes+1;j++)
        {
            if(i==0 || j==0)
            {
            printf("(%d)",g->adj[i][j]);
            }
            else
            {
            printf(" %d ",g->adj[i][j]);   
            }
        }
        printf("\n");
    }
}

void addEdge (Graph *g, int sourceI, int destI)
{
    g->adj[sourceI][destI]=1;
    g->adj[destI][sourceI]=1;
    g->no_edges= g->no_edges++;
}

void graph_details(Graph *g)
{
    printf("No of nodes : %d",g->no_nodes);
    printf("\nNo of edges: %d",g->no_edges);
}

int main()
{
    Graph *g;
    //initializing graph
    graph_init(&g,5); // nodes = 5

    //printing graph details

    //adding edges..

    //edge 1--->2
    //edge 2-->1
    addEdge(g,1,2);

    addEdge(g,3,5);

    addEdge(g,1,3);

    //printing the adjacency matrix...
    graph_details(g);
    printf("\n");
    print_graph(g);
}
import java.util.ArrayList;


public class Graph_DFS
{

    ArrayList<ArrayList<Integer>> adjacencyList; // adjacency list
    int V; //max vertex number

    public Graph_DFS(int V)
    {
        this.V=V;
        adjacencyList = new ArrayList<>();

       for(int i=0;i<V;i++)
       {
        adjacencyList.add(new ArrayList<>());
       }
    }

    //For undirected Graph..
    public void addEdge(int sourceV, int destinationV)
    {
        this.adjacencyList.get(sourceV).add(destinationV);
        this.adjacencyList.get(destinationV).add(sourceV);
    }

    public static void dfsTravel(int node, boolean[] visited, ArrayList<ArrayList<Integer>> adjList, ArrayList<Integer> solution)
    {
        visited[node] = true;
        solution.add(node);

        for(Integer neighbour : adjList.get(node))
        {
            if(visited[neighbour]==false)
            {
                dfsTravel(neighbour, visited, adjList, solution);
            }
        }
    }

    //Implemented DFS TRAVERSAL With java
   public  ArrayList<Integer> DFS()
   {
    ArrayList<Integer> solution = new ArrayList<>();
    boolean visited[] = new boolean[this.V];
    dfsTravel(1, visited, this.adjacencyList, solution);
    return solution;
   }
    public static void main(String[] args)
    {
        Graph_DFS g = new Graph_DFS(9);
        g.addEdge(1, 2);
        g.addEdge(1, 6);
        g.addEdge(2,3);
        g.addEdge(2,4);
        g.addEdge(6,7);
        g.addEdge(6,8);
        g.addEdge(4, 5);
        g.addEdge(7, 5);       


        ArrayList<Integer> dfs  = g.DFS();
        System.out.println(dfs);
    }
}
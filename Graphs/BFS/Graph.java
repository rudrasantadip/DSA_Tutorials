import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

public class Graph
{

    ArrayList<ArrayList<Integer>> adjacencyList; // adjacency list
    int V; //max vertex number

    public Graph(int V)
    {
        this.V=V;
        adjacencyList = new ArrayList<>();

       for(int i=0;i<V;i++)
       {
        adjacencyList.add(new ArrayList<>());
       }
    }

    public void addEdge(int sourceV, int destinationV)
    {
        this.adjacencyList.get(sourceV).add(destinationV);
        this.adjacencyList.get(destinationV).add(sourceV);
    }

    //Implemented BFS TRAVERSAL With java
    public ArrayList<Integer> BFS(Integer startingNode)
    {
        ArrayList<Integer> solution = new ArrayList<>(); // array list to store the solution set
        boolean visited[] = new boolean[this.V]; // array to check for visited nodes
        Queue<Integer> q = new LinkedList<>(); // Queue to store the current node and its neighbours...

        q.add(startingNode); // add the starting node
        visited[startingNode]=true; // set the visited of the starting node to true...

        while (!q.isEmpty()) // perform until the queue becomes empty..
        {
            Integer node = q.poll(); // dequeue the First element... it the starting node..
            solution.add(node); // add it to the bfs solution array
            
            for(Integer neighbour : this.adjacencyList.get(node))
            {
                if(visited[neighbour]==false)
                {
                    visited[neighbour]=true;
                    q.add(neighbour);
                }
            }

        }
        return solution;
    }
    public static void main(String[] args)
    {
        Graph g = new Graph(9);
        g.addEdge(1, 2);
        g.addEdge(1, 6);
        g.addEdge(2,3);
        g.addEdge(2,4);
        g.addEdge(6,7);
        g.addEdge(6,8);
        g.addEdge(4, 5);
        g.addEdge(7, 5);


        ArrayList<Integer> bfs  =   g.BFS(6);
        System.out.println(bfs);
            
    }
}
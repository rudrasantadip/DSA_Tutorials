import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Pair
{
    int predecessor;
    int child;

    public Pair(int child,int predecessor)
    {
        this.predecessor=predecessor;
        this.child=child;
    }
}

class Graph
{
    int V;
    ArrayList<ArrayList<Integer>> adjList;

    public Graph(int V)
    {
        this.V=V;

        adjList = new ArrayList<>();
        for(int i=0;i<V;i++)
        {
            adjList.add(new ArrayList<>());
        }
    }

    public void addEdge(int sourceNode, int destNode)
    {
        this.adjList.get(sourceNode).add(destNode);
        this.adjList.get(destNode).add(sourceNode);
    }

    public void bfs(Graph g, int startingNode, ArrayList<Integer> soln, int [] visited)
    {
        Queue<Integer> q = new LinkedList<>();
        visited[startingNode]=1;
        q.add(startingNode);
        while (!q.isEmpty()) 
        {
            Integer node = q.poll();
            soln.add(node);
            
            for(Integer neighbour : g.adjList.get(node))
            {
                if(visited[neighbour]==0)
                {
                    visited[neighbour]=1;
                    q.add(neighbour);
                }
            }
        }
    }

    private boolean isCycle( int startingNode, int [] visited)
    {
        Queue<Pair> q = new LinkedList<>();
        visited[startingNode]=1;
        q.add( new Pair(startingNode,-1)); // child, parent
        while (!q.isEmpty()) 
        {
            Pair node = q.poll();
            
            for(Integer neighbour : this.adjList.get(node.child))
            {
                if(visited[neighbour]==0)
                {
                    visited[neighbour]=1;
                    q.add(new Pair(neighbour, node.child));
                    System.out.println(neighbour+" "+node.child);
                }
                else if(node.predecessor!=neighbour)
                {
                    return true;
                }
            }
        }

        return false;

    }

    public boolean isCyclic()
    {
        int visited []= new int[this.V];
        for (int i=0;i<this.V;i++)
        {
            if(visited[i]==0)
            {
                if(this.isCycle(i, visited)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }

    public ArrayList<Integer> BFS(Graph g, int startingNode)
    {
        int [] visited = new int[g.V];
        ArrayList<Integer> solution = new ArrayList<>();

        for(int i=0;i<g.V;i++)
        {
            if(visited[i]==0)
            {
                this.bfs(g, i, solution, visited);
            }
        }
   
        return solution;
    }
}


class CycleDetector {

    public static void main(String[] args)
    {
        Graph g = new Graph(5);
        g.addEdge(0, 4);
        g.addEdge(1, 3);

        System.out.println(g.adjList);
        System.out.println(g.isCyclic());
    }
}
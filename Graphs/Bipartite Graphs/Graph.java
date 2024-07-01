import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Graph
{
    ArrayList<ArrayList<Integer>> adjacencyList;
    int V;

    public Graph(int V)
    {
        this.adjacencyList = new ArrayList<>();
        this.V=V;
        for(int i=0;i<V;i++)
        {
            this.adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int source, int destination)
    {
        this.adjacencyList.get(source).add(destination);
        this.adjacencyList.get(destination).add(source);
    }

    public static boolean check(int start, Graph g, int [] color)
    {
        Queue<Integer> nodes  = new LinkedList<>();
        color[start]=0;

        while (!nodes.isEmpty())
        {
            int node = nodes.poll();
            
            for(int neighbour : g.adjacencyList.get(node))
            {
                if(color[neighbour]==-1)
                {
                    color[neighbour] = 1- color[node];
                    nodes.add(neighbour);
                }
                else if(color[neighbour]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isBipartite()
    {
        int [] color = new int[this.V];
        for(int i=0;i<color.length;i++)
        {
            color[i]=-1;
        }

        for(int i=0;i<color.length;i++)
        {
            if(color[i]==-1)
            {
                if(check(i, this, color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }


    public static void main(String[] args) {
        Graph g = new Graph(6);

        g.addEdge(0, 1);
        g.addEdge(2, 1);
        g.addEdge(2, 3);
        g.addEdge(1, 5);
        g.addEdge(5, 4);
        g.addEdge(3, 4);

        System.out.println(g.isBipartite());

    }
}
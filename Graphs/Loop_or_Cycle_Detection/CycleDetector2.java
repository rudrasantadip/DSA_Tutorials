import java.util.*;;

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

    
}



public class CycleDetector2 
{

    public static void main(String[] args)
    {
        Graph g = new Graph(5);

        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);


    }
}

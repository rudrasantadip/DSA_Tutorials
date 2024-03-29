/**
 * Given a grid of size nXm , n = no of rows and m = no of columns
 * consisting of 0s (water) and 1s (land),
 * Find the number of islands.
 * An island is sorrounded by water on all sides, and connected adjacent 
 * lands, in all 8 directions 
 */

import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Pair
{
    int x,y;

    public Pair(int x, int y)
    {
        this.x=x;
        this.y=y;
    }
}

class Graph
{
    int V;
    ArrayList<ArrayList<Integer>> adjacencyList;

    public Graph(int V)
    {
        this.V=V;
        this.adjacencyList = new ArrayList<>();
        for(int i=0;i<V+1;i++)
        {
            this.adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int source, int destination)
    {
        this.adjacencyList.get(source).add(destination);
        this.adjacencyList.get(destination).add(source);
    }

    public int[][] toAdjMatrix()
    {
        int [][] adjM = new int[this.V+1][this.V+1];

        for(int i=0;i<this.adjacencyList.size();i++)
        {
            for( int j=0;j<this.adjacencyList.get(i).size();j++)
            {
                adjM[i][this.adjacencyList.get(i).get(j)]=1;
            }
        }
        return adjM;
    }
} 

public class Question2 
{
    static void bfs(int row, int col, int [][] visited, char [][] grid)
    {
        visited[row][col]=1;
        int n = grid.length;
        int m = grid[0].length;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(row, col));

        while (!q.isEmpty())
        {
            // Pair node = new Pair(q.peek().x, q.peek().y);
            Pair node = q.poll();

            // q.remove();
            
            for(int delX=-1;delX<=+1;delX++)
            {
                for(int delY=-1;delY<=+1;delY++)
                {
                    int x  = node.x+delX;
                    int y = node.y+delY;

                    if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==0 && grid[x][y]=='1' )
                    {
                        visited[x][y]=1;
                        q.add( new Pair(x, y));
                    }
                }
            }
        }

    }

    public static int numOfIslands(char [][] grid)
    {
        int cnt=0;
        int n = grid.length;
        int m = grid[0].length;

        int [][] visited = new int[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }
    public static void main(String[] args)
    {
            char [][] grid =
            {
            {'0','1','1','1','0','0','0'},
            {'0','0','1','1','0','1','0'}
            };

            int n = numOfIslands(grid);
            System.out.println(n);
    }
}

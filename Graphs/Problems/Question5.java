/*
 * Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. 
There should be atleast one 1 in the grid.
 */
import java.util.*;;

class Node
{
    int x;
    int y;
    int step;

    public Node(int x, int y, int step)
    {
        this.x=x;
        this.y=y;
        this.step=step;
    }
}


public class Question5
{
    public static int [][] nearest(int [][]grid)
    {
        int n= grid.length;
        int m = grid[0].length;
        int [][] dist= new int[n][m];
        int [][] visited = new int[n][m];
        Queue<Node> q = new LinkedList<Node>();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    visited[i][j]=1;
                    q.add(new Node(i,j,0));
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while (!q.isEmpty())
        {
            Node node = q.poll();
            dist[node.x][node.y]=node.step;

            for(int i=0;i<4;i++)
            {
                int row = node.x+delRow[i];
                int col = node.y+delCol[i];

                if(row>=0 && row < n && col>=0 && col<m && visited[row][col]==0)
                {
                    visited[row][col]=1;
                    q.add(new Node(row, col, node.step+1));
                }
            }

        }
        return dist;
    }
    public static void main(String[] args) 
    {
        int grid [][] = {{1,0,1},{1,1,0},{1,0,0}};   
        int soln[][] = nearest(grid);

        for(int i=0;i<soln.length;i++)
        {
            for(int j=0;j<soln[i].length;j++)
            {
                System.out.print(soln[i][j]);
            }
            System.out.println();
        }
    }
}
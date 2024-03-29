/*
 * Flood Fill Algorithm 
 * An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels
(also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
 */

import java.io.*;
public class Question3
{
 
        public static void main(String[] args) throws IOException
        {
            int[][] image =  {
                {1,1,1},
                {1,1,0},
                {1,0,1}
            };
    
            // sr = 1, sc = 1, newColor = 2       
            Solution obj = new Solution();
            int[][] ans = obj.floodFill(image, 1, 1, 2);
            for(int i = 0; i < ans.length; i++){
                for(int j = 0; j < ans[i].length; j++)
                    System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }   




    
    class Solution
    {

        static void dfs(int row,int col, int [][] image, int [][] coloredImage, int[] delRow, int [] delCol, int newColor, int initColor)
        {
            int n = image.length;
            int m  = image[0].length;
            coloredImage[row][col]=newColor;
            for(int i=0;i<delRow.length;i++)
            {
                int nRow = row+delRow[i];
                int nCol = col+delCol[i];

                if( nRow>=0 && nRow<n && nCol>=0 && nCol<m && coloredImage[nRow][nCol]!=newColor && image[nRow][nCol]==initColor)
                {
                    dfs(nRow, nCol, image, coloredImage, delRow, delCol, newColor, initColor);
                }
            }
            
        }   

        public int[][] floodFill(int[][] image, int sr, int sc, int newColor)
        {
            int coloredImage [][] = image;
            int delRow[] = {-1,0,1,0};
            int delCol[]={0,1,0,-1};
            int initColor = image[sr][sc];

            dfs(sr,sc,image,coloredImage,delRow,delCol,newColor,initColor);
            return coloredImage;
        }
    }

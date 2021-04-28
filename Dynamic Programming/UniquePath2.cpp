/*
Unique Paths II

Solution
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:

0 0 0 
0 1 0 
0 0 0

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
   Hide Hint #1  
The robot can only move either down or right. Hence any cell in the first row can only be reached from the cell left to it. However, if any cell has an obstacle, you don't let that cell contribute to any path. So, for the first row, the number of ways will simply be
if obstacleGrid[i][j] is not an obstacle
     obstacleGrid[i,j] = obstacleGrid[i,j - 1] 
else
     obstacleGrid[i,j] = 0
You can do a similar processing for finding out the number of ways of reaching the cells in the first column.
   Hide Hint #2  
For any other cell, we can find out the number of ways of reaching it, by making use of the number of ways of reaching the cell directly above it and the cell to the left of it in the grid. This is because these are the only two directions from which the robot can come to the current cell.
   Hide Hint #3  
Since we are making use of pre-computed values along the iteration, this becomes a dynamic programming problem.
if obstacleGrid[i][j] is not an obstacle
     obstacleGrid[i,j] = obstacleGrid[i,j - 1]  + obstacleGrid[i - 1][j]
else
     obstacleGrid[i,j] = 0
     */


class Solution {
    int total_row;
    int total_col;
public:
    int traverse(vector<vector<int>>& grid,int row, int col,vector<vector<int>>& visited)
    {
        if(row > total_row || col > total_col)
            return 0;
        
        if(grid[row][col] == 1)
        {
            visited[row][col] = 0;
            return 0;
        }
        
        if(row  == total_row && col == total_col)
            return 1;
   
        if(visited[row][col])
            return visited[row][col];
        
        visited[row][col] = traverse(grid,row,col+1,visited) + traverse(grid,row+1,col,visited);
        
        return visited[row][col];    
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        total_row = obstacleGrid.size()-1;
        total_col = obstacleGrid[total_row].size()-1;
        
        vector<int> vec_col(total_col+1,0);
        vector<vector<int>> visited(total_row+1,vec_col);
      
        return traverse(obstacleGrid,0,0,visited);
        
    }
};

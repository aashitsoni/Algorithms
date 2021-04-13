/*
Number of Islands

Solution
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

void dfs(char** grid, int gridRowSize,int gridColSize,int row,int col)
{
    grid[row][col]= '0';
    
    if(row-1 >=0 && grid[row-1][col] == '1')dfs(grid,gridRowSize,gridColSize,row-1,col);
    if(row+1 < gridRowSize && grid[row+1][col] == '1' ) dfs(grid,gridRowSize,gridColSize,row+1,col);
    if(col-1 >=0 && grid[row][col-1]=='1' ) dfs(grid,gridRowSize,gridColSize,row,col-1);
    if(col+1 < gridColSize && grid[row][col+1] == '1') dfs(grid,gridRowSize,gridColSize,row,col+1);
}
int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int numIsland = 0;
    if(gridSize <= 0)
        return 0;
    
    for(int row = 0; row<gridSize;row++)
        for(int col = 0; col < *gridColSize;col++)
        {
            if(grid[row][col] == '1')
            {
                ++numIsland;
                dfs(grid,gridSize,*gridColSize,row,col);
            }
                
        }
    return numIsland;

}
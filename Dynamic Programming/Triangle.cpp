/*
120.Triangle
Medium

Solution
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or 
index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

/*
This is classic example of Dynamic programming. - it has elements of recursions.
It can be divided into sub prolems of sub-subproblems. Each subproblems have overlapping characteristics.
If we do memoization it will help us no recompute the same thing again and again. Hence it will save the CPU
cycle. Otherwise it will be so time consuming.
*/
class Solution {
public:
    
    int minSum(vector<vector<int>>& sum_vec, vector<vector<int>>& triangle,int row, int idx)
    {
        int val = 0;
        int size = triangle.size()-1;

        if(row < size) 
        {
            int sum = 0;
            int sum1 = 0;
        
            val = triangle[row][idx];
            
            //find some of next row and same index lets call it sum
            sum = sum_vec[row+1][idx];
            if(sum == INT_MIN)
                sum  = minSum(sum_vec,triangle,row+1,idx);

            // find a sum of next row and +1 index. lets call it sum1
            sum1 = sum_vec[row+1][idx+1];
            if(sum1 == INT_MIN)
                sum1 = minSum(sum_vec,triangle,row+1,idx+1);

            // compare sum to sum1 and we will pick the one that is less of eachother.
            if(sum < sum1)
                val+= sum;
            else
                val+= sum1;

            // lets assign the sum to the - sum_vec memoization for the DP.
            sum_vec[row][idx] = val;
        }
        else if( row == size)
        {
            sum_vec[row][idx] = triangle[row][idx];
            val = triangle[row][idx];
        }
            
        
        return val;
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int size = triangle.size();
        int rowsize = triangle[size-1].size();
        
        // to initialization the memoization with some default value
        vector<int> row(rowsize,INT_MIN);
        
        // sum-vec is fully initializaed with INT_MIN values.
        vector<vector<int>>sum_vec (size,row);
    
        // lets call the recursion now.
        return minSum(sum_vec,triangle,0,0);
        
    }
};
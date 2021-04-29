/*
Pascal's Triangle II

Solution
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/

class Solution {
public:
    void pascal(vector<int>& vec,int row)
    {
        if(row == 0)
            return;
        int i = 1;
        vector<int> prev(vec);
        vec[0]=1;
        for(i = 1;i<prev.size();i++)
            vec[i] = prev[i-1]+prev[i];
        vec.push_back(1);
        pascal(vec,row-1);
        
        
    }    
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        vec.push_back(1);
        
        if(rowIndex > 0)
            pascal(vec,rowIndex);
        
        return vec;
    }
};

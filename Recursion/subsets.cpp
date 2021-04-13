/*
Subsets

Solution
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

class Solution {
    vector<vector<int>> m_subsets;
public:
    void combine(int n)
    {
        int size = m_subsets.size();
        
        for(int i = 0;i < size; i++)
        {
            vector<int> elements(m_subsets[i]);
            elements.push_back(n);
            m_subsets.push_back(elements);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        m_subsets.push_back(vector<int>()); //enter empty set
        
        for(int i = 0; i< nums.size();i++)
        {
            combine(nums[i]);
        }
        
        return m_subsets;
        
    }
};

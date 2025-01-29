/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

// a backtracking solution
class Solution {
    vector<int> mNums;
public:
    void dfs( int startIndex, vector<int>& path, vector<vector<int>>& res ) {
        if( startIndex == mNums.size() ) {
            res.emplace_back( path );
            return;
        }
        for( auto edge: mNums ) {
            if( find( path.begin(), path.end(), edge) != path.end() ) 
                continue;
            
            path.emplace_back( edge );
            dfs( startIndex+1, path, res );
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if( nums.size() > 0 ) {
            vector<int> path;
            mNums = nums;
            dfs( 0, path, res );
        }
        return res;
    }
};

// iterative solution
class Solution {
    int size;
    vector<vector<int>> final_vec;
public:
    void perm(vector<int>& nums,int first)
    {
        if(first >= size)
        {
            final_vec.push_back(nums);
            return;
        }
        
        
        for(int i = first; i<size;i++)
        {
            int tmp = nums[first];
            nums[first] = nums[i];
            nums[i] = tmp;
            
            perm(nums,first+1);
            
            tmp = nums[first];
            nums[first] = nums[i];
            nums[i] = tmp;
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        size = nums.size();
        perm(nums,0);
        
        return final_vec;
        
        
    }
};
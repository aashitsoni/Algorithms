/*
Permutations II

Solution
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution {
    int size;
    set<vector<int>> dups;
public:
   void perm(vector<int>& nums,int first)
    {
        if(first >= size)
        {
            if(dups.find(nums) == dups.end())
                dups.insert(nums);
            return;
        }
        
        
        for(int i = first; i<size;i++)
        {
            // swap number i and first 
            int tmp = nums[first]; 
            nums[first] = nums[i];
            nums[i] = tmp;
            
            perm(nums,first+1);
            
            // swap the number back.
            tmp = nums[first];
            nums[first] = nums[i];
            nums[i] = tmp;
            
        }
        
    }
  
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        size = nums.size();
        perm(nums,0);
 
        vector<vector<int>> v(dups.begin(),dups.end());
        return v;
        
    }
};


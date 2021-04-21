/*
41. First Missing Positive
Hard
Given an unsorted integer array nums, find the smallest missing positive integer.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

0 <= nums.length <= 300
-231 <= nums[i] <= 231 - 1

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
  
    map<int,int> visited;
 
    int smallest = 1;
    int i ;
    for(i = 0; i<nums.size();i++)
    {
        if(smallest == nums[i])
            while(visited.find(++smallest) != visited.end());
            
        visited[nums[i]] = 1;
        
    }
    return smallest;
}
};
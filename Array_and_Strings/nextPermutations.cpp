/*
Next Permutation

Solution
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int size = nums.size();
        int i = size-2;
        int j = size-1;
        vector<int>::iterator itr = nums.end();
        --itr;
        // find the first decreasing element from the right
        while(i>=0 && nums[i] >= nums[i+1])
        {
            --i;
            --itr;
        }
        
        // find the one element that is bigger than nums[i]
        if(i>=0)
        {
            int temp;
            
            while(j>=0 && nums[j]<=nums[i])
                --j;
            
            // when found just swap the element and reverse the string from next to i upto end.
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
         }
        std::reverse(itr,nums.end());
    }
};
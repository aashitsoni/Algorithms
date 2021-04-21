/*
33. Search in Rotated Sorted Array
Medium

7459

655

Add to List

Share
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: Can you achieve this in O(log n) time complexity?
*/
class Solution {
public:
    
    int searchBST(vector<int>& nums,int l, int r,int target)
    {
        int m = (l + r)/2;
        if(l > r)
            return -1;
        
   //     printf("l=%d,r=%d,m=%d\n",nums[l],nums[r],nums[m]);
        if(nums[m]==target)
            return m;
        else if(nums[m]<target)
            return searchBST(nums,m+1,r,target);
        else 
            return searchBST(nums,l,m-1,target);
        
    }
    int search(vector<int>& nums, int target) {
        int i;
        int m;
        if(nums.empty())
            return -1;
        if(nums.size()==1)
        {
            if(nums[0]== target)
                return 0;
            return -1;
        }
        for(i = 1;i<nums.size();i++)
            if(nums[i]<nums[i-1])
                break;
        m = searchBST(nums,0,i-1,target);
        
        if(m == -1)
            m = searchBST(nums,i,nums.size()-1,target);
        
        return m;
        
        
    }
};

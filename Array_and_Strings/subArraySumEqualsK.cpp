/*
Subarray Sum Equals K

Solution
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

int arraySum(int*nums,int start,int end,int k)
{
    int matches = 0;
    int left = start;
    int right = start+1;
    
    int sum = nums[left];
    
    while(right<end)
    {
        if(sum == k)
            matches++;
        sum +=nums[right++];
        
    }
    
    while(left < end)
    {
        if(sum == k)
            matches++;
        sum-=nums[left++];
    }
    return matches;
}


int subarraySum(int* nums, int numsSize, int k)
{
    int matches = 0;
    int left = 0;
    int right = numsSize;
  
    while(left <= right)
    {
        matches+=arraySum(nums,left,right,k);
        left++;
        right--;
            
    }
    
    
    return matches;
    
}

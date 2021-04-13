/*
Find First and Last Position of Element in Sorted Array

Solution
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    bool bfound = false;
    int low = 0;
    int high = numsSize-1;
    int mid = low;
    int *output = malloc(2*sizeof(int));
    *returnSize = 2;
    output[0]=output[1]=-1;
    
    // check the boundary conditions before running the algorithm
    if(numsSize <= 0 || target < nums[low] || target > nums[high])
        return output;
    
    while(low < high)
    {
        mid = (low+high)/2; // this may sometime overflow - doing mid = low + (high-low)/2 is much safer. if the high's value is at the boudnary.

        if(target == nums[mid])
            break;
        else if(target == nums[low])
        {
            mid = low;
            break;
        }
        else if(target == nums[high])
        {
            mid = high;
            break;
        }
        else  if(target < nums[mid])
            high = mid-1;
        else 
            low = mid+1;

    }
 
    if(target == nums[mid])
    {
        low = high = mid;

        while(low >= 0 && nums[low] == target )
                        low--;

        while(high < numsSize && nums[high] == target)
            high++;

        output[0] = low+1;

        output[1] = high-1;

    }
    return output;

}

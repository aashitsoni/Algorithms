/*
11. Container With Most Water
Medium

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

//using sliding windows from left to right decreasing every steps and compairing max area - 

int maxArea(int* height, int heightSize)
{
    int min_h = 0;
    int min_d = 0;
    int max_area = 0;
    int area;
    
    int l = 0;
    int r = heightSize-1;
    
    while(l < r)
    {
        min_h = (height[l] < height[r])?height[l]:height[r];
        min_d = r-l;
        
        area = min_h*min_d;
        
        if(area > max_area)
            max_area = area;
        if(height[l] == min_h)
            l++;
        else
            r--;
        
    }
    return max_area;
    
    
}
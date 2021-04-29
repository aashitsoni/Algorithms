/*
Climbing Stairs

Solution
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

// basically its like fibonacci number - progression. just one level ahead - like f(2) = 2 not 1. so that means it is f(3).
class Solution {
    map<int,int> climb_map;
public:
    int climb(int n)
    {
        if(climb_map.find(n) != climb_map.end())
            return climb_map[n];
        
        if(n < 2) // if it is only 1 step or 2 step - it has those many ways to climb.
            return n;
        
        int steps = climb(n-1)+climb(n-2);
        climb_map[n] = steps;
        return steps;
    }
    int climbStairs(int n) {
        return climb(n+1);
        
        
    }
};

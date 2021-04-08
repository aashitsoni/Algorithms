/*
@copyright : Aashit Soni email: aashit@bu.edu

Maximize Distance to Closest Person

Solution
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the 
ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

 

Example 1:


Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Example 3:

Input: seats = [0,1]
Output: 1
 

Constraints:

2 <= seats.length <= 2 * 104
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.

*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int leading_zeros=0,trailing_zeros=0;
        int size = seats.size();
        bool prevZero=false;
        int start=0;
        int max_len = INT_MIN;
        int i = 0;
        
        //find if leading zeros
        for(i= 0;i<size && seats[i]==0;i++,leading_zeros++);
        
        //find the trailing zeros
        for(i = size-1;i>=0 && seats[i]==0;i--,trailing_zeros++);
      
        size -=trailing_zeros;
        
        
        for(i = leading_zeros;i<size;i++)
        {
            if(seats[i]==0)
            {
                if(!prevZero)
                {
                    start = i;
                    prevZero = true;
                }
            }
            else
            {
                if(prevZero)
                {
                    if(max_len < i-start)
                        max_len = i-start;
    
                    prevZero=false;
                }
                
            }
        }
        max_len = (max_len+1)/2;
      
        if(max_len > leading_zeros && max_len > trailing_zeros)
            return max_len;
        
        if(leading_zeros>trailing_zeros)
            return leading_zeros;
        else
            return trailing_zeros;
        
    }
};
/*
 Reverse String

Solution
Write a function that reverses a string. The input string is given as an array of characters s.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
 

Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    void reverse(vector<char>&s, int l, int r)
    {
        if(l < r)
        {
            char ch = s[l];
            s[l]=s[r];
            s[r]=ch;
            reverse(s,l+1,r-1);
        }
    }
    
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
        
        
    }
};

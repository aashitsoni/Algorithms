/*
Valid Parentheses

Solution
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
class Solution {
public:
    bool isValid(string s) 
    {
        int size = s.size();
        stack<char> bracesStack;
        int i;
        for( i = 0;i<size;i++)
        {
            if(s[i] == ')' || s[i] == '}' || s[i]== ']')
            {
                if(bracesStack.empty())
                    break;
                
                if(s[i]!=bracesStack.top())
                        break;
                bracesStack.pop();
            }
            else
            {
                if(s[i] == '(')
                    bracesStack.push(')');
                else if(s[i]=='{')
                    bracesStack.push('}');
                else
                    bracesStack.push(']');
                
            }
        }
     
        
        if(i < size || !bracesStack.empty())
            return false;
        
    
        return true;
    }
};
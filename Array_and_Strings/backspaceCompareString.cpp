/*

Backspace String Compare

Solution
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c".
Example 4:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/

void removeBackSpace(char* s)
{
    int j = 0;
    int len = strlen(s);
    for(int i = 0;i<len;i++)
        {
        if(s[i]=='#' )
        {
            if(j > 0)
               j--;
        
        }else
            s[j++] = s[i];
    }
    s[j] = 0;
    return ;
    
}

bool backspaceCompare(char * s, char * t){
        
    removeBackSpace(s);
    removeBackSpace(t);
    
  
    
    return !strcmp(s,t);
    
}
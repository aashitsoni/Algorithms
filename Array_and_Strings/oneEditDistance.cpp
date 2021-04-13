/*
One Edit Distance

Solution
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.
 

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "a", t = ""
Output: true
Example 4:

Input: s = "", t = "A"
Output: true
 

Constraints:

0 <= s.length <= 104
0 <= t.length <= 104
s and t consist of lower-case letters, upper-case letters and/or digits.
*/

bool _processOneEditDist(char* s,int len_s, char *t,int len_t)
{
    int i = 0;
    int iCompare = 0;
    
    while(i < len_s && s[i] == t[i])
        i++;
    
    if(i >= len_s)
    {
        if(len_t -i == 1)
            return true;
        
        return false;
    }
    
    if(len_s == len_t)
        iCompare = strcmp(s+i+1,t+i+1);
    else 
        iCompare = strcmp(s+i,t+i+1);
    
    if(iCompare == 0)
        return true;
    
    return false;
    
}

bool isOneEditDistance(char * s, char * t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    int diff_in_length = len_s - len_t;
    
    if(diff_in_length < -2 || diff_in_length > 2)
        return false;
    
    if(len_s > len_t)
        return _processOneEditDist(t,len_t,s,len_s);
    else
        return _processOneEditDist(s,len_s,t,len_t);

}
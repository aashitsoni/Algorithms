/*
Remove All Adjacent Duplicates in String II

Solution
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
   Hide Hint #1  
Use a stack to store the characters, when there are k same characters, delete them.
   Hide Hint #2  
To make it more efficient, use a pair to store the value and the count of each character.
*/
bool trimDuplicates(char*str,int k)
{
    int length = strlen(str);
    int i = 0;
    int j = 0;
    char prev = 0;
    int char_map[256] = {0};
    
    while(j < length)
    {
        if(prev != str[j])
            char_map[prev]=0;
        
        char_map[str[j]]++;
        str[i] = str[j];
        
        if(char_map[str[j]] == k)
        {
            i-=k;
            char_map[str[j]] = 0;
        }
        prev = str[j];
        i++;
        j++;
        
    }
    str[i] = 0;
    
    if(i == j)
        return false;
    
    return true;
    
    
}

char * removeDuplicates(char * s, int k)
{
    int length = strlen(s)+1;
    char* str =  (char*) malloc(length);
    strcpy(str,s);
    
    while(trimDuplicates(str,k) == true);
    
    return str;
}

/*
14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/



char * longestCommonPrefix(char ** strs, int strsSize)
{
    char* common_prefix;
    int i,j;
    int size;
    
    if(strsSize <=0)
        return "";
    
    size = strlen(strs[0])+1;
    
    common_prefix = (char*)calloc(size,sizeof(char) ) ;
    strcpy(common_prefix,strs[0]);
    
    for(i =1;i <strsSize;i++)
    {
        size = strlen(strs[i]);
        for(j = 0;j <size && common_prefix[j] == strs[i][j];j++);
        
        common_prefix[j] = 0;
        
    }
    return common_prefix;
    

}
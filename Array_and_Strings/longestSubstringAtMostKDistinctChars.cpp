/*Longest Substring with At Most K Distinct Characters

Solution
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
 

Constraints:

1 <= s.length <= 5 * 104
0 <= k <= 50
*/

int lengthOfLongestSubstringKDistinct(char * s, int k){
    int char_map[256]={0};
    int s_len = strlen(s);
    int right,left,window;
    int distinct_char=0;
    window = -1;
    right = 0;
    left = 0;
    
    
    while(right <= s_len)
    {
        if(distinct_char > k)
        {
            if(--char_map[s[left]] == 0)
                distinct_char--;
            
            left++;
        }
        else
        {
            
            if(window < right-left)
                window = right-left;

            if(char_map[s[right]]++ == 0)
                distinct_char++;
        
            right++;
        }

      }
        
    return window;



}
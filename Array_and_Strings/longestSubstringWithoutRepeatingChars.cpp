/**
Longest Substring Without Repeating Characters

Solution
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

// sliding window flexible - longest template based solution: 
// look at the template - here: https://algo.monster/templates

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> charSet;
        int max = 0;
        int ans = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++ ) {
            ans++;
            while ( charSet.find(s[ right ] ) != charSet.end() ) {
                charSet.erase( s[left] );
                left++;
                ans--;
            }
            charSet.insert( s[right] );
            max = std::max(max,ans);
        }
        return max;
    }
 };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int i=0,j,temp=0; //temp denotes the starting position of the largest such substring
        int ans=0,ans_temp=0;
        int ch[250];
        for(i=0;i<250;i++){
            ch[i]=-1;
        }
        i=0;
        while(i<len){
            int c=(int)s[i];
            if(ch[c]>=temp){
                ans_temp=i-temp;
                ans=ans>ans_temp ? ans : ans_temp;
                temp=ch[c]+1;
            }
            ch[c]=i;
            i++;
        }
        ans_temp=i-temp;
        ans=ans>ans_temp ? ans : ans_temp;
        return ans;
    }
};



/*C solution*/

int lengthOfLongestSubstring(char * s)
{
    int i,j,ans,len;
    int char_map[255]={0};
    
    i=j=ans = 0;
    len = strlen(s);
    
    while (j < len)
    {
        if(char_map[s[j]] == 0)
        {
            if(ans < j-i+1)
                ans = j-i+1;
            char_map[s[j]]=1;
            ++j;
        }
        else
        {
            char_map[s[i]]=0;
            ++i;
        }
        
           
    }
    return ans;
         
}
/*
Minimum Window Substring

Solution
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
 

Constraints:

1 <= s.length, t.length <= 105
s and t consist of English letters.
 

Follow up: Could you find an algorithm that runs in O(n) time?
*/

class Solution {
    map<char,int> search_map;
public:
    void constructSearchMap(string t)
    {
        for(int i =0;i<t.size();i++)
            search_map[t[i]]++;
      /*  {
            if(search_map.find(t[i]) == search_map.end())
                search_map[t[i]] = 1;
            else
                search_map[t[i]]++;
        }*/
    }
    
    bool isValidSubString(map<char,int>& char_map)
    {
        map<char,int>::iterator search_it;
        map<char,int>::iterator char_it;
        
        for(search_it = search_map.begin();search_it!=search_map.end();search_it++)
        {
            char_it = char_map.find(search_it->first);
            if(char_it == char_map.end())
                return false;
            
            if(char_it->second < search_it->second)
                return false;
        }
        return true;
            
    }
    
    string minWindow(string s, string t) 
    {
        map<char,int> char_map;
        map<char,int>::iterator it;
        int window = INT_MAX;
        string out_str;
        
        int l,r;
        
        l = 0;
        r = 0;
        constructSearchMap(t);
        
        while(r<s.size())
        {
            
            if(isValidSubString(char_map) == true)
            {
                if(window > r-l)
                {
                    window = r-l;
                    out_str = s.substr(l,window);
                }
                
                it = char_map.find(s[l]);
           
                if(--char_map[s[l]] == 0)
                    char_map.erase(it);
       
                l++;
            }
            else
            {
                if(r<s.size())
                {
                char_map[s[r]]++;
                r++;
                }
            }
            
        }
       while(isValidSubString(char_map) == true && l< s.size())
        {
            if(window > r-l)
            {
                window = r-l;
                out_str = s.substr(l,window);
            }

            it = char_map.find(s[l]);
            if(--char_map[s[l]] == 0)
                char_map.erase(it);

            l++;
       }
    
        return out_str;
            
    }
};
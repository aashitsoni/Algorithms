/*Group Anagrams

Solution
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> anagram_map;
        string sortedStr;
        for(int i = 0;i<strs.size();i++)
        {
            sortedStr = strs[i];
            sort(sortedStr.begin(),sortedStr.end());
            auto it = anagram_map.find(sortedStr);
            
            if(it != anagram_map.end())
            {
                vector<string>& string_vec = it->second;
             
                string_vec.push_back(strs[i]);
            }
            else
            {
                vector<string> string_vec;
                string_vec.push_back(strs[i]);
                anagram_map[sortedStr] = string_vec;
            }
                
        }
        
        //return vector<vector<string>>(anagram_map.begin(),anagram_map.end());
        
        vector<vector<string>> string_2d_vec;
        
        auto it = anagram_map.begin();
        while(it != anagram_map.end())
        {
            string_2d_vec.push_back(it->second);
            it++;
            
            
        }
        
        return string_2d_vec;
        
    }
};
/*
Copyright : Aashit Soni : aashit@bu.edu. 

Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  
In these strings like "heeellooo", we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".

For some given string S, a query word is stretchy if it can be made to be equal to S by any number of applications of the following extension operation: 
choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is 3 or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has size less than 3.  
Also, we could do another extension like "ll" -> "lllll" to get "helllllooo".  If S = "helllllooo", then the query word "hello" would be stretchy because of these 
two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.

Given a list of query words, return the number of words that are stretchy. 


Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.


Constraints:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters


*/

class Solution {
  public:
    int expressiveWords(string S, vector<string>& words) 
    {
        int count = 0;
        
        for(int i = 0; i<words.size();i++)
        {
            int k = 0;
            int j = 0;
            char prev = 0;// cache the previous character to find the duplicates as well as run the logic to see if the stretchyness is intact.
            int dup = 0; // each repeating characters in total - every time it resets if the character changes.
            
            // if the word is longer than the stretchy word it does not make any sense to 
            // iterate this loop.
            if(words[i].size() > S.size())
                continue;
            
            while(j<words[i].size() && k < S.size())
            {
                
                if(words[i][j] == S[k])
                {
                    if(prev == S[k])
                        dup++;
                    else 
                        dup = 0;
                    
                    prev = S[k];
                    j++;
                    k++;
                }
                else
                {
                    while(S[k]==prev)
                    {
                        k++;
                        dup++;
                    }
                    if(dup < 2)
                        break;
                    
                    dup = 0;// reset the duplicate count.
                }
                
            }
            if(k == S.size() && j == words[i].size())
                count++;
            else
            {
                
                while(k < S.size() && S[k] == prev)
                {
                    dup++;
                    k++;
                }
            
                if(k == S.size() && dup >=2)
                    count++;
            }
            
        
        }
        return count;
        
    }
};
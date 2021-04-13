/*
Letter Combinations of a Phone Number

Solution
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
    vector<string> _combination;
    map<char,string> _charmap;
    int dig_len;
public:
    void init_char_map()
    {
        _charmap['2']="abc";
        _charmap['3']="def";
        _charmap['4']="ghi";
        _charmap['5']="jkl";
        _charmap['6']="mno";
        _charmap['7']="pqrs";
        _charmap['8']="tuv";
        _charmap['9']="wxyz";
        
    }
    void generateCombo(string digits,int pos, string sofar)
    {
        if(pos < dig_len)
        {
            string c = _charmap[digits[pos]];
            for(int i = 0;i < c.length();i++)
                generateCombo(digits,pos+1,sofar+c[i]);
        }
        else
            _combination.push_back(sofar);
        
        return;
        
        
    }
    vector<string> letterCombinations(string digits) 
    {
        
        init_char_map();
        dig_len = digits.length();
        if(dig_len > 0)
             generateCombo(digits,0,"");
        
        return _combination;
        
    }
};
/* 
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

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
    int mDigitsLength;
    string mDigits;
    std::map<char,std::vector<char>> phoneMap;
public:
    void init(string& digits) {
        std::vector<char> vec1 = {};
        std::vector<char> vec2 = {'a','b','c'};
        std::vector<char> vec3 = {'d','e','f'};
        std::vector<char> vec4 = {'g','h','i'};
        std::vector<char> vec5 = {'j','k','l'};
        std::vector<char> vec6 = {'m','n','o'};
        std::vector<char> vec7 = {'p','q','r','s'};
        std::vector<char> vec8 = {'t','u','v'};
        std::vector<char> vec9 = {'w','x','y','z'};
        std::vector<char> vec0 = {};
        phoneMap['0'] = vec0;
        phoneMap['1'] = vec1;
        phoneMap['2'] = vec2;
        phoneMap['3'] = vec3;
        phoneMap['4'] = vec4;
        phoneMap['5'] = vec5;
        phoneMap['6'] = vec6;
        phoneMap['7'] = vec7;
        phoneMap['8'] = vec8;
        phoneMap['9'] = vec9;
        mDigits = digits;
        
    }
    std::vector<char>& getEdges( int startIndex ) {
        if( startIndex < mDigits.length() ) {
            return phoneMap[ mDigits[startIndex] ];
        }
        return phoneMap['0'];
    }
    
    void dfs(int startIndex, std::vector<char>& path,std::vector<string>& res ) {
        if( startIndex == mDigits.length() ) {
            string str( path.begin(), path.end());
            res.emplace_back( str );
            return;
        }
        for( auto edge: getEdges( startIndex ) ) {
            path.emplace_back(edge);
            dfs( startIndex+1, path, res );
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        std::vector<char> path;
        std::vector<string> res;
        if( digits.length() > 0 ) {
            init( digits );
            dfs(0,path,res);
        }
        return res;
    }
};
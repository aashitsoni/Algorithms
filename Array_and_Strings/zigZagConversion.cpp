/*
6. ZigZag Conversion
Medium
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

class Solution {
public:
    string convert(string s, int numRows) {
        string* str_vec = new string[numRows];
        int i = 0;
        int j = 0;
        string zigzag;
        
        while(j<s.size())
        {
            i = 0;
            while(i < numRows && j < s.size())
                str_vec[i++].push_back(s[j++]);
            i-=2;
            while(i > 0 && j < s.size())
                str_vec[i--].push_back(s[j++]);
        }
        
        for(i = 0; i<numRows;i++)
        {
            cout<<str_vec[i]<<endl;
            zigzag+=str_vec[i];
        }
        return zigzag;
        
    }
};
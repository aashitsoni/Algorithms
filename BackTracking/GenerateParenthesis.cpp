/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
    int mTotalParens;
public:
    
    bool valid( std::vector<char>& path ) {
        std::stack<char> stack1;
        for( auto ch : path ) {
            if( ch == '(' ) {
                stack1.push(ch);
            } else {
                if( stack1.empty() )
                    return false;
                stack1.pop();
            }
        }
        return stack1.empty();
    }
    
    std::vector<char> getEdges() {
        std::vector<char> pairVec = { '(',')' };
        return pairVec;
    }
    
    void dfs( int startIndex, std::vector<char>& path, vector<string>& res ){
        if( startIndex >= mTotalParens ) {
            if( valid( path ) ) {
                string str( path.begin(), path.end() );
                res.emplace_back( str );
            } 
            return;
        }
        for( auto edge: getEdges() ) {
            path.emplace_back(edge);
            dfs( startIndex+1, path, res );
            path.pop_back();
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        std::vector<string> res;
        std::vector<char> path;
        if( n > 0 ) {
            mTotalParens = n*2;
            dfs(0, path, res );
        }
        return res;
    }
};
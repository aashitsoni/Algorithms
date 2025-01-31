/* 
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 * 
 */

/* Solution 1 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Breath first search - algo - with inline insertion
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if( root==nullptr ) return res;
        bool left_to_right = true;
        std::queue<TreeNode*> level;
        level.push( root );
        
        while( !level.empty() ) {
            int n = level.size();
            std::list<int> list;
            for( int i=0; i<n; i++) {
                TreeNode* node = level.front();
                if( left_to_right ) {
                    list.emplace_back( node->val );
                }
                else {
                    list.emplace_front( node->val );
                }
                if( node->left ){
                    level.push( node->left);
                }
                if( node->right ){
                    level.push( node->right );
                }
                
                level.pop();
            }
            left_to_right = !left_to_right;
            res.push_back( std::vector<int>( list.begin(), list.end() ) );
        }
        return res;
    }
};

/* Soultion 2 */
class Solution {
    vector< vector< int > > zigVec;
public:
    void storeValue( int value, int level ) {
        if( level > zigVec.size() ) {
            vector<int> newVec;
            newVec.push_back( value );
            zigVec.push_back( newVec );
        } else {
            zigVec[ level-1 ].push_back( value );
        }
    }
    
    void buildVector( TreeNode* node, int level ) {
        if( node ) {
            storeValue( node->val, level );
            buildVector( node->left, level+1 );
            buildVector( node->right, level+1 );
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        buildVector( root, 1 );
        
        // reverse the even level
        for(int i = 0; i < zigVec.size(); i++ ) {
            if( i % 2 == 1 ) {
                std::reverse( zigVec[i].begin(), zigVec[i].end() );
            }
        }
        
        return zigVec;
    }
};
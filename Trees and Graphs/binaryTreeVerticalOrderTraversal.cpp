/*
Binary Tree Vertical Order Traversal

Solution
Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Example 2:


Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
Example 3:


Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]
Example 4:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
 */

class Solution {
    map<int,vector<int>> verticals;
    vector<TreeNode*> nodes;
    vector<int> columns;
    
    
public:
    void traverse(TreeNode*root)
    {
        int i = 0;
        int idx;
        struct TreeNode* node;
        
        nodes.push_back(root);
        columns.push_back(0);
        
        while(i < nodes.size())
        {
            idx = columns[i];
            node = nodes[i];
            
            if(verticals.find(idx) == verticals.end())
                verticals[idx] = vector<int>();
            
            verticals[idx].push_back(node->val);
            
            if(node->left)
            {
                
                nodes.push_back(node->left);
                columns.push_back(idx-1);
            }
            if(node->right)
            {
                nodes.push_back(node->right);
                columns.push_back(idx+1);
            }
            i++;
            
        }
    
    }
    
    
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        map<int,vector<int>>::iterator itr;
        vector<vector<int>> vec_2d=vector<vector<int>>();
        int i = 0;
        if(root)
        {
           traverse(root);
           for(i=0,itr = verticals.begin();itr!=verticals.end();itr++,i++)
                vec_2d.push_back(itr->second);
            
        }
        return vec_2d;
        
        
        
        
    }
};
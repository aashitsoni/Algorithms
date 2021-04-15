/*
Deepest Leaves Sum

Solution
Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:
                      1
                     / \
                    2   3
                   / \   \
                  4   5   6
                 /         \
                7           8


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100
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
    map<int,int> level_sums;
    int max_level;
    
public:
    void traverse(TreeNode* root,int level)
    {
        if(root == NULL)
            return;
        if(max_level < level)
            max_level = level;
        
        level_sums[level]+=root->val;
        
        traverse(root->left, level+1);
        traverse(root->right, level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) 
    {
        traverse(root,0);
        
        return level_sums[max_level];
        
        
    }
};

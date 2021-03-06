/*
Maximum Depth of Binary Tree

Solution
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:
               3
              / \
             9   20
               /    \
              15     7


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:
             1
              \
               2

Input: root = [1,null,2]
Output: 2
Example 3:

Input: root = []
Output: 0
Example 4:

Input: root = [0]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
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

// avoid tail recursion - if you do tail recursion you may need to do the - extra accounting.
class Solution {
public:
    int traverse(TreeNode* root)
    {
        int left, right;
        
        if(root == NULL)
            return 0;
        
        left = traverse(root->left)+1;
        right = traverse(root->right)+1;
        
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return traverse(root);
        
    }
};
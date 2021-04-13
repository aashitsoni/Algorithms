/*
Binary Tree Paths

Solution
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
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
    vector<string> _paths;
public:
    
    void traverse(TreeNode* root, string path)
    {
        char str[10];
        if(root == NULL)
            return;
        sprintf(str,"%d",root->val);
        
        path+=str;
        if(root->left == NULL && root->right == NULL)
        {
            _paths.push_back(path);
            return;
         }
        
        path+="->";
        traverse(root->left,path);
        traverse(root->right,path);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root,"");
        return _paths;
        
    }
};
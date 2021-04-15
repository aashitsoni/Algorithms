/*
@copyright Aashit Soni : Leed code Challenge problem - April 2021 Week 2

Inorder Successor in BST

Solution
Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:
                   2
                  / \
                 1   3 


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.


Example 2:

                       5
                     /   \
                    3     6
                   / \
                  2   4
                 /
                1


Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
All Nodes will have unique values.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* next;
bool found = false;
struct TreeNode* traverse(struct TreeNode* root, struct TreeNode* p)
{
 
    if(root !=NULL)
    {
        
        traverse(root->left,p);
        
        if(found == true)
        {
            next = root;
            found = false;
        }
  
        if(root == p)
            found = true;

        traverse(root->right,p);
    }
    return root;
    
}
struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    
    found = false;
    next = NULL;
    
    traverse(root,p);
    return next;
    
    
}

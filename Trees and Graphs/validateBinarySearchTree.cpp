/*
Validate Binary Search Tree

Solution
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_LIMIT -0x80000000;
#define DEF_GANDU 1;

long min;
bool gandu;


int f(struct TreeNode* root)
{
    if(root == NULL)
        return gandu;
    
    
    if(gandu == true)
    {
        f(root->left);
        if(min >= root->val) // the min is larger that the value - out of order now. So its not BST
        {
            gandu=false;
            return gandu;
        }
        min = root->val; // asign the minimum values
        f(root->right);
    }
    
    return min;
    
}
bool isValidBST(struct TreeNode* root)
{
    gandu = true;
    min = (long)INT_MIN -1;
   
    f(root);
    return gandu;
    
       
}


 
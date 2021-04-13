/*
Binary Tree Maximum Path Sum

Solution
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

 

Example 1:
           1
          / \
         2   3 

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
               -10
               /  \
              9   20
                 /  \
                15   7


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max_path;

int max_gain(struct TreeNode* root)
{
    int left_gain,right_gain,price_newpath;
    

    if(root==NULL)
        return 0;

    left_gain = right_gain= 0;
    
    price_newpath = root->val;
    
    if(root->left)
    {
        
        left_gain = max_gain(root->left);
        
        if(left_gain > 0)
            price_newpath += left_gain;
    }
    if(root->right)
    {
        right_gain = max_gain(root->right);
        if(right_gain > 0)
            price_newpath +=right_gain;
       
    }
    
    if(max_path < price_newpath)
        max_path = price_newpath;
    
    return price_newpath;
  }

int maxPathSum(struct TreeNode* root)
{
    max_path=INT_MIN; // initilize before every run
    max_gain(root);
    return max_path;
    
}
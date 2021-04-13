/*
Binary Tree Right Side View

Solution
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

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
public:
/*    vector<int> rightSideView(TreeNode* root) 
    {
        vector<TreeNode*> next;
        vector<int> rightside;
        if(root!=NULL)
        {
        
            next.push_back(root);

            while(!next.empty())
            {
                int i,prev_val;
                int size;
                vector<TreeNode*> current(next);
                next.clear();

                i = 0;
                size=current.size();


                while(i< size)
                {
                    if(current[i]->left)
                        next.push_back(current[i]->left);
                    if(current[i]->right)
                        next.push_back(current[i]->right);
                    prev_val = current[i]->val;
                    i++;
                }
                rightside.push_back(prev_val);
            }
        }

        return rightside;
    }
*/
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<TreeNode*> next;
        vector<int> rightside;
        int outer = 0;
        int low,high;
        
        low = 0;
        high = 0;
        if(root!=NULL)
        {
            next.push_back(root);
            outer++;
            
            while(low < outer)
            {
                high = outer;
                while(low < high)
                {
                    if(next[low]->left)
                    {
                        next.push_back(next[low]->left);
                        outer++;
                    }
                    if(next[low]->right)
                    {
                        next.push_back(next[low]->right);
                        outer++;
                    }
                    low++;
                }
                rightside.push_back(next[high-1]->val);
            }
        }

        return rightside;
    }

};
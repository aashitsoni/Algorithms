/*
24. Swap Nodes in Pairs
Medium

Given a linked list, swap every two adjacent nodes and return its head.

 

Example 1:

Input: head = [1,2,3,4]
1 -> 2 -> 3 -> 4
Output: [2,1,4,3]
2 -> 1 -> 4 -> 3


Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
 

Follow up: Can you solve the problem without modifying the values in the list's nodes? (i.e., Only nodes themselves may be changed.)
*/


/*Recursive*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* swap(ListNode* ptr)
    {
        ListNode* node;
        ListNode* tmp;
        
        if(ptr == NULL)
            return NULL;
     
        node = ptr->next;
        
        if(node)
        {
            tmp = node->next; // node - that is next to next.
            node->next = ptr;
            ptr->next = swap(tmp);
           return node;
        }
        return ptr;
            
    }
    ListNode* swapPairs(ListNode* head) {
        head = swap(head);
        return head;
        
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*Iterative*/
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* ptr = head;
    struct ListNode* next = NULL;
    struct ListNode* end = NULL;
    if(!head)
        return head;
    
    next = head->next;
    
    while(ptr !=NULL && next !=NULL)
    {
        end = next->next;
        
        next->next = ptr; //reverse the node
        
        if(prev )
            prev->next= next;
        else
            head = next;
        
        prev = ptr;
        ptr = end;
        
        if(ptr)
            next = ptr->next;
        
    }
    if(prev)
        prev->next = end;
    
    return head;
    

}
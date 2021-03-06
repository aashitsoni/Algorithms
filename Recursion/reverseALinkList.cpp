/*Reverse Linked List

Solution
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* start = NULL;
struct listNode* reverse(struct ListNode* ptr)
{
    struct ListNode* tmp = NULL;


    if(ptr == NULL)
        return NULL;
    
    tmp = reverse(ptr->next);
    
    if(tmp)
        tmp->next=ptr;
    else
        start = ptr;
    
    return ptr;
    
    
}

struct ListNode* reverseList(struct ListNode* head)
{
    start = NULL;
    head = reverse(head);
   
    if(head)
        head->next = NULL;
    
    return start;
    

}
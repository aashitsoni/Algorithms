/*
Reorder List

Solution
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* findMiddle(struct ListNode* head)
{
    struct ListNode* slow= head;
    struct ListNode* fast= head;
    
    while(fast != NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* tmp = NULL;
    while(head!=NULL)
    {
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
        
    }
    return prev;
}

void mergeTwoList(struct ListNode* l1, struct ListNode*l2)
{
    struct ListNode* tmp1;
    struct ListNode* tmp2;
    
    
    while(l2->next)
    {
        tmp1 = l1->next;
        tmp2 = l2->next;
        l1->next = l2;
        l2->next = tmp1;
        l2 = tmp2;
        l1 = tmp1;
    }
    return;
    
}

void reorderList(struct ListNode* head)
{
    struct ListNode* middle;
    struct ListNode* reverse_list;    
    middle = findMiddle(head);
    if(middle)
    {
        reverse_list = reverseList(middle);
        mergeTwoList(head,reverse_list);
    }
    
    
}
/*
Remove Nth Node From End of List

Solution
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



int removeRecursive(struct ListNode* head,int n,struct ListNode* prev)
{
    if(head)
    {
        int i = removeRecursive(head->next,n,head);
        
        if(i == 0)
        {
            // remove this element;
            if(prev == NULL) // this is first element
                return 0;
            else
                prev->next = head->next;
        }
        return --i;

    }
    
    return --n;
    
    
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
/*    int total = 0;
    struct ListNode* start = head;
    struct ListNode* prev = NULL;
    
    for( ;start != NULL;start=start->next,total++);
    
    total = total - n ;
    
    
    for(start = head;total>0;total--)
    {
        prev = start;
        start = start->next;
    }
    
    if(prev)
        prev->next = start->next;
    
    if(head == start)
        head = start->next;
    
    return head;
*/
    int i = removeRecursive(head,n,NULL);
    if(i == 0)
        head = head->next;
    
    return head;
    
}
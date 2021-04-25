/*
Remove Nth Node From End of List

Solution
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:

1 --> 2 --> 3 --> 4 --> 5

n = 2

output : 1 -->2 -->3 -->5

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

/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int traverse(struct ListNode* head,struct ListNode* prev,int n)
{
    if(head)
    {   
        int i = traverse(head->next,head,n);
        if(i == n)
        {
            if(prev)
                prev->next = head->next;
            else
                return i;
            
        }
        ++i;

        return i;
    }
    return 1;   
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int i ;
    i = traverse(head,NULL,n);
    
    if(n == i)
       head = head->next;
    
    return head;
    
}*/
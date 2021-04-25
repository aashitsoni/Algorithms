/*
25. Reverse Nodes in k-Group
Hard

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
 

Example 1:



Input: head = [1,2,3,4,5], k = 2
1 --> 2 --> 3 --> 4 --> 5

Output: [2,1,4,3,5]

2 --> 1 --> 4 --> 3 --> 5

Example 2:


Input: head = [1,2,3,4,5], k = 3
1 --> 2 --> 3 --> 4 --> 5

Output: [3,2,1,4,5]
3 --> 2 --> 1 --> 4 --> 5

Example 3:
Input: head = [1,2,3,4,5], k = 1
1 --> 2 --> 3 --> 4 --> 5

Output: [1,2,3,4,5]
4 --> 3 --> 2 --> 1 --> 5

Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// the end node is - sentinal - end. we are not reversing that node. 

struct ListNode* reverseKList(struct ListNode* start, struct ListNode* end)
{
    struct ListNode* ptr = start->next;
    struct ListNode* prev = start;
    struct ListNode* tmp;
    
    // reverse each node  between start to the end (sentinel) node.
    while(ptr!=end)
    {
        tmp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = tmp;
    }
    // points the first node to the sentinel node now which is after the reverse.
    start->next = end;
 
    return end;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    
    struct ListNode* start= head;
    struct ListNode* ptr = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;
    int i = 0;
    while(ptr!=NULL)
    {
        if(++i == k)
        {
           // printf("start=%d,End=%d\n",start->val,ptr->val);
       
            i = 0;
            // reverse the list starting from start to ptr - ptr -> next is going to be the next start and that is what is 
            // returned from the function.
            next = reverseKList(start,ptr->next);
            
            // if the prev - from the start is NULL we modify the head poitner. so that we can return back.
            if (prev == NULL)
                head = ptr;
            else
                prev->next = ptr; // point the prev->next to the end of the list which is reversed now.
        
            // point back ptr to start - as the list is reverse. point the prev also to the start - so that we can use it in the next iteration.
            // point the start to the end of the list that is reversed. - Basically the pointer that is returned ferom the reverseKList - i.e ptr-> next that was given to the
            // function.
            ptr = start;
            prev = start;
            start = next;
            
        }
        // move ptr to the next element.
        ptr = ptr->next;
    }
    
    return head;
    
}
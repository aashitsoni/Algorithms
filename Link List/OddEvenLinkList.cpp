/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
*/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy;
        ListNode* pOdd = head;
        if( head == nullptr )
            return nullptr;
        ListNode* pEven = head->next;
        ListNode* tmp = head->next;
        int i = 1;
        while( pEven != nullptr && pOdd!= nullptr ) {
            // event node
            if( i % 2 == 0 ) {
                pEven->next = pOdd->next;
                pEven = pEven->next;
                
            } else {
                pOdd->next = pEven->next;
                dummy = pOdd;
                pOdd = pOdd->next;
                
            }
            i++;
        }
        if(pOdd == NULL )
            pOdd = dummy;
        pOdd->next = tmp;        
    return head;
    }
};
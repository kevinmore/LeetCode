/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        
        ListNode* p1 = head;
        ListNode* begin = p1->next;
        
        if (m == 1)
        {
            p1 = NULL;
            begin = head;
        }
        else
        {
            while (m > 2)
            {
                p1 = p1->next;
                --m;
            }
            begin = p1->next;
        }
        
        ListNode* end = head;
        while(n > 1)
        {
            end = end->next;
            --n;
        }
        
        ListNode* p2 = (end->next != NULL) ? end->next : NULL;
        
        // start reversing
        ListNode* reversedHead = NULL;
        while(begin != p2)
        {
            ListNode* temp = begin;
            begin = begin->next;
            temp->next = reversedHead;
            reversedHead = temp;
        }
        
        ListNode* reversedTail = reversedHead;
        while(reversedTail->next != NULL)
        {
            reversedTail = reversedTail->next;
        }
        reversedTail->next = p2;
        
        if (p1 != NULL)
        {
            p1->next = reversedHead;
            return head;
        }
        else
        {
            return reversedHead;   
        }
        
    }
};
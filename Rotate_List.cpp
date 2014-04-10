// http://oj.leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        int len = 1;
        ListNode* p = head;
        while(p->next)
        {
            ++len;
            p = p->next;
        }
        
        // if k > len
        k = len - k % len;
        
        // connect tail and head
        p->next = head;
        
        for (int i = 0; i < k; ++i)
        {
            p = p->next;
        }
        
        // break the circle
        head = p->next;
        p->next = NULL;
        return head;
        
    }
};
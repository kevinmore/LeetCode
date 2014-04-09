// http://oj.leetcode.com/problems/add-two-numbers/
// Time Complexity: O(n+m)

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* head = new ListNode(0);
        int carry = 0;
        ListNode* prev  = head;
        for (ListNode *pa = l1, *pb = l2; pa != NULL || pb != NULL;
            pa = (pa == NULL) ? NULL : pa->next, 
            pb = (pb == NULL) ? NULL : pb->next, 
            prev = prev->next)
        {
            const int ai = (pa == NULL) ? 0 : pa->val;
            const int bi = (pb == NULL) ? 0 : pb->val;
            const int digit = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(digit);
        }
        if (carry > 0) prev->next = new ListNode(carry);
        return head->next;
    }
};
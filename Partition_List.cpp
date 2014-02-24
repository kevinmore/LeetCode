// http://oj.leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) return head;
        ListNode left_dummy(0);
        ListNode right_dummy(0);
        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;
        
        for (; head; head = head->next) 
        {
            if (head->val < x) 
            {
                left_cur->next = head;
                left_cur = head;
            } 
            else 
            {
                right_cur->next = head;
                right_cur = head;
            }
        }
        
        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;
        return left_dummy.next;
    }
};
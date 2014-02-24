// http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return head;
        ListNode dummy(INT_MIN); // ??????
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        while (cur != nullptr) 
        {
            bool duplicated = false;
            
            while (cur->next != nullptr && cur->val == cur->next->val) 
            {
                duplicated = true;
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            
            if (duplicated) 
            {
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = cur;
        return dummy.next;
    }
};
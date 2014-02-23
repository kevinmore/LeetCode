// http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // recursive
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode dummy(head->val + 1);
        dummy.next = head;
        
        recur(&dummy, head);
        return dummy.next;
    }
private:
    static void recur(ListNode *prev, ListNode *cur)
    {
        if (!cur) return;
        
        if (prev->val == cur->val) 
        {
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        }
        else
        {
            recur(prev->next, cur->next);
        }
    }
};

 // iterate
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        for (ListNode* prev = head, *cur = head->next; cur; cur = cur->next)
        {
            if (prev->val == cur->val)
            {
                prev->next = cur->next;
                delete cur;
            }
            else
            {
                prev = cur;
            }
        }
        return head;
    }
};
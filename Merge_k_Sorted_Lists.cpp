// http://oj.leetcode.com/problems/merge-k-sorted-lists/
// Time Complexity: O(n1+n2+...), Space Complexity: O(1)

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
		ListNode *p = lists[0];
		for (int i = 1; i < lists.size(); i++) {
			p = mergeTwoLists(p, lists[i]);
		}
		return p;
    }
	
	// Merge Two Sorted Lists
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
	{
		ListNode head(-1);
		for (ListNode* p = &head; l1 != nullptr || l2 != nullptr; p = p->next) 
		{
			int val1 = l1 == nullptr ? INT_MAX : l1->val;
			int val2 = l2 == nullptr ? INT_MAX : l2->val;
			if (val1 <= val2) 
			{
				p->next = l1;
				l1 = l1->next;
			} 
			else 
			{
				p->next = l2;
				l2 = l2->next;
			}
		}
		return head.next;
	}
};
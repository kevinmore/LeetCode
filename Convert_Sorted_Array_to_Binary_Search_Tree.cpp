// http://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Time Complexity: O(n), Space Complexity: O(logn)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(), num.end());
    }
    
    template<typename RandomAccessIterator>
    TreeNode* sortedArrayToBST (RandomAccessIterator first, 
        RandomAccessIterator last)
    {
        const auto length = distance(first, last);
        
        if (length <= 0) return nullptr;
        auto mid = first + length / 2;
        TreeNode* root = new TreeNode (*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);
        
        return root;
    }
};
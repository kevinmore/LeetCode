// http://oj.leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root) {
        return balancedHeight (root) >= 0;
    }
    
    /**
    * Returns the height of `root` if `root` is a balanced tree,
    * otherwise, returns `-1`.
    */
    int balancedHeight(TreeNode *root)
    {
        if (root == NULL) return 0;
        
        int left = balancedHeight(root->left);
        int right = balancedHeight(root->right);
        
        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
};
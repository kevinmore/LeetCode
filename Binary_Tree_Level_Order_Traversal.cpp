// http://oj.leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == nullptr) return result;
        queue<TreeNode*> current_level, next_level;
        vector<int> level; // elments in level level
        current_level.push(root);
        while (!current_level.empty()) 
        {
            while (!current_level.empty()) 
            {
                TreeNode* node = current_level.front();
                current_level.pop();
                level.push_back(node->val);
                if (node->left != nullptr) next_level.push(node->left);
                if (node->right != nullptr) next_level.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(next_level, current_level); //!!! how to use swap
        }
        return result;
    }
};
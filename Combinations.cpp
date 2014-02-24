// http://oj.leetcode.com/problems/combinations/
// Time Complexity: O(n!), Space Complexity: O(n)

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(n, k, 1, 0, path, result);
        return result;
    }
    
private:
    static void dfs(int n, int k, int start, int cur,
        vector<int> &path, vector<vector<int> > &result) 
    {
        if (cur == k) 
        {
            result.push_back(path);
        }
        for (int i = start; i <= n; ++i) 
        {
            path.push_back(i);
            dfs(n, k, i + 1, cur + 1, path, result);
            path.pop_back();
        }
    }
};
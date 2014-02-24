// http://oj.leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int f[n];
        fill(f, f+n, INT_MAX);
        f[0] = 0;
        for (int i = 0; i < m; i++) 
        {
            f[0] += grid[i][0];
            for (int j = 1; j < n; j++) 
            {?
                f[j] = min(f[j - 1], f[j]) + grid[i][j];
            }
        }
        return f[n - 1];
    }
};
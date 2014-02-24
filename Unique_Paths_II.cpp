// http://oj.leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        this->f = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
        return dfs(obstacleGrid, m, n);
    }
private:
    vector<vector<int> > f; // buffer
    
    int dfs(const vector<vector<int> > &obstacleGrid, int x, int y) 
    {
        if (x < 1 || y < 1) return 0;
        if (obstacleGrid[x-1][y-1]) return 0;
        if (x == 1 and y == 1) return 1;
        return getOrUpdate(obstacleGrid, x - 1, y) + getOrUpdate(obstacleGrid, x, y - 1);
    }
    
    int getOrUpdate(const vector<vector<int> > &obstacleGrid, int x, int y) 
    {
        if (f[x][y] > 0) return f[x][y];
        else return f[x][y] = dfs(obstacleGrid, x, y);
    }
};
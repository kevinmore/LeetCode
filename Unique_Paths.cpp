// http://oj.leetcode.com/problems/unique-paths/

// Time Complexity: O(n^4), Space Complexity: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m == 1 && n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

// Time Complexity: O(n^2), Space Complexity: O(n^2)
class Solution {
public:
	int uniquePaths(int m, int n) {
		this->f = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
		return dfs(m, n);
	}
	
private:
	vector<vector<int> > f; // buffer
	int dfs(int x, int y) 
	{
		if (x < 1 || y < 1) return 0;
		if (x == 1 && y == 1) return 1;
			return getOrUpdate(x - 1, y) + getOrUpdate(x, y - 1);
	}
	
	int getOrUpdate(int x, int y) 
	{
		if (f[x][y] > 0) return f[x][y];
		else return f[x][y] = dfs(x, y);
	}
};

// Time Complexity: O(n^2), Space Complexity: O(n)
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> f(n, 0);
		f[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				f[j] = f[j - 1] + f[j];
			}
		}
		return f[n-1];
	}
};
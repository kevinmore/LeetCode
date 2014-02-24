// http://oj.leetcode.com/problems/subsets/
// Time Complexity: O(2^n), Space Complexity: O(n)

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }
private:
    static void subsets(const vector<int> &S, vector<int> &path, int step,
        vector<vector<int> > &result) 
    {
        if (step == S.size()) 
        {
            result.push_back(path);
            return;
        }
        // do not choose S[step]
        subsets(S, path, step + 1, result);
        // choose S[step]
        path.push_back(S[step]);
        subsets(S, path, step + 1, result);
        path.pop_back();
    }
};
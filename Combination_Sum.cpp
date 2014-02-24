// http://oj.leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> intermediate;
        dfs(nums, target, 0, intermediate, result);
        return result;
    }
    
private:
    void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate,
            vector<vector<int> > &result) 
    {
        if (gap == 0) {
            result.push_back(intermediate);
            return;
    }
        for (size_t i = start; i < nums.size(); i++) 
        {
            if (gap < nums[i]) return;
            intermediate.push_back(nums[i]);?
            dfs(nums, gap - nums[i], i, intermediate, result);
            intermediate.pop_back();
        }
    }
};

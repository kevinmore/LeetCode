// http://oj.leetcode.com/problems/3sum/
// Time Complexity: O(n^2), Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> result;
        if (num.size() < 3) return result;
        sort(num.begin(), num.end());
        const int target = 0;
        auto last = num.end();
        for (auto a = num.begin(); a < prev(last, 2); a = upper_bound(a, prev(last, 2), *a)) 
        {
            for (auto b = next(a); b < prev(last); b = upper_bound(b, prev(last), *b)) 
            {
                const int c = target - *a - *b;
                if (binary_search(next(b), last, c))
                    result.push_back(vector<int> { *a, *b, c });
            }
        }
        return result;
    }
};
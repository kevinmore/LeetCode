// http://oj.leetcode.com/problems/3sum-closest/
// Time Complexity: O(n^3)

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        
        sort(num.begin(), num.end());
        
        for (auto a = num.begin(); a != prev(num.end(), 2); a = upper_bound(a, prev(num.end(), 2), *a))
        {
            auto b = next(a);
            auto c = prev(num.end());
            
            while (b < c)
            {
                const int sum = *a + *b + *c;
                const int gap = abs(sum - target);
                
                if (gap < min_gap)
                {
                    result = sum;
                    min_gap = gap;
                }
                
                if (sum < target)
                    b = upper_bound(b, c, *b);
                else
                    c = prev(lower_bound(b, c, *c));
            }
        }
        
        return result;
    }
};
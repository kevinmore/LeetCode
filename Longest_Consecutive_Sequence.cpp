// http://oj.leetcode.com/problems/longest-consecutive-sequence/
// Time Complexity: O(n)

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int, bool> used;
        for (auto i : num) used[i] = false;
        int longest = 0;
        for (auto i : num) 
        {
            if (used[i]) continue;
            int length = 1;
            used[i] = true;
            for (int j = i + 1; used.find(j) != used.end(); ++j)
            {
                used[j] = true;
                ++length;
            }
            for (int j = i - 1; used.find(j) != used.end(); --j)
            {
                used[j] = true;
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
}
};
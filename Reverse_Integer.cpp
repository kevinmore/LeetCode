// http://oj.leetcode.com/problems/reverse-integer/
// Time Complexity: O(logn), Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        for (; x; x /= 10)
            r = r * 10 + x % 10;
            
        return r;
    }
};
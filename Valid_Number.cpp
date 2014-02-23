// http://oj.leetcode.com/problems/valid-number/
// Using sorted() here, Time Complexity: O(n)

class Solution {
public:
    bool isNumber(const char *s) {
        char* endptr;
        strtod (s, &endptr);
        if (endptr == s) return false;
        for (; *endptr; ++endptr)
            if (!isspace (*endptr)) return false;
            
        return true;
    }
};
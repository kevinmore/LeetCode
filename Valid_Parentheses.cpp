// http://oj.leetcode.com/problems/valid-parentheses/
// Time Complexity: O(n), Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for (auto c : s) 
        {
            if (left.find(c) != string::npos) 
            {
                stk.push (c);
            } 
            else 
            {
                if (stk.empty () || stk.top () != left[right.find (c)])
                    return false;
                else
                    stk.pop ();
            }
        }
        return stk.empty()
    }
};
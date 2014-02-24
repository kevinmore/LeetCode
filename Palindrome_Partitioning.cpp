// http://oj.leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> output;
        DFS(s, 0, output, result);
        return result;
    }

private:
    void DFS(string &s, int start, vector<string>& output,
            vector<vector<string>> &result) 
    {
        if (start == s.size()) 
        {
            result.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); i++) 
        {
            if (isPalindrome(s, start, i)) 
            {?????
                output.push_back(s.substr(start, i - start + 1));
                DFS(s, i + 1, output, result);???
                output.pop_back();???
            }
        }
    }
};
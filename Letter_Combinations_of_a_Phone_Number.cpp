// http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        dfs(digits, 0, "", result);
        return result;
    }

private:
    const vector<string> keyboard {
        " ", // '0'
        "", // '1'
        "abc", // '2'
        "def", // ...
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void dfs(const string &digits, size_t cur, string path,
            vector<string> &result) 
        {
            if (cur == digits.size()) {
                result.push_back(path);
                return;
            }
            for (auto c : keyboard[digits[cur] - '0']) 
            {
                dfs(digits, cur + 1, path + c, result);
            }
        }
};
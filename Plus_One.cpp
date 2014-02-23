// http://oj.leetcode.com/problems/plus-one/
// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i;
        for(i=digits.size()-1;i>=0;--i){
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                ++digits[i];
                return digits;
            }
        }
        if(i<0) digits.insert(digits.begin(),1);
        return digits;
    }
};
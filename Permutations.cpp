// http://oj.leetcode.com/problems/permutations/
// Time Complexity: O(n!), Space Complexity: O(1)

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        
        vector<vector<int>> permutations;
        
        do 
        {
            permutations.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        
        return permutations;
    }
};
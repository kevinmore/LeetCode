// http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0) return n;
        int pos = 0;
        for(int i = 1; i < n; ++i) {
            if (A[pos] != A[i])
                A[++pos] = A[i];
        }
        return pos + 1;
    }
};
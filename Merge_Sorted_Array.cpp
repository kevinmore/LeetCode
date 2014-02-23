// http://oj.leetcode.com/problems/merge-sorted-array/
// Time Complexity: O(m+n), Space Complexity: O(1)

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ia = m - 1, ib = n - 1, icur = m + n - 1;
        while(ia >= 0 && ib >= 0) 
        {
            A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
        }
        while(ib >= 0) 
        {
            A[icur--] = B[ib--];
        }
    }
};
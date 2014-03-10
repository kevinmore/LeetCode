// http://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Time Complexity: O(log (m+n))

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1) // odd number
            return find_kth(A, m, B, n, total / 2 + 1);
        else
            return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2;
    }
    
private:
    static double find_kth(int A[], int m, int B[], int n, int k)
    {
        // assume m <= n
        if (m > n) return find_kth(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);
        // divide k into two parts
        int pa = min(k / 2, m), pb = k - pa;
        if (A[pa - 1] < B[pb - 1])
            return find_kth(A + pa, m - pa, B, n, k - pa);
        else if (A[pa - 1] > B[pb - 1])
            return find_kth(A, m, B + pb, n - pb, k - pb);
        else
            return A[pa - 1];
    }
};
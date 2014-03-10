// http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Time Complexity: O(n)

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 0) return 0;
        
        int pos = 0;
        int count = 1;
        for (int i = 1; i < n; ++i)
        {
            if (A[pos] != A[i])
            {
                A[++pos] = A[i];
                count = 1;
                
            }
            else
            {
                if (count < 2)
                {
                    A[++pos] = A[i];
                    ++count;
                }
            }
        }
        
        return pos + 1;
    }
};
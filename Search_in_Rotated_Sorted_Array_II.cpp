// http://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Time Complexity: O(log(n))

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n <= 0) return false;
        int first = 0, last = n;
        while (first != last)
        {
            int mid = (first + last) / 2;
            if (A[mid] == target)
                return true;
            if (A[first] < A[mid])
            {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;
            }
            else if (A[first] > A[mid])
            {
                if (A[mid] <= target && target <= A[last - 1])
                    first = mid + 1;
                else
                    last = mid;
            }
            else
            {
                //skip duplicate one, A[start] == A[mid]
                first++;
            }
        }
        
        return false;
    }
};
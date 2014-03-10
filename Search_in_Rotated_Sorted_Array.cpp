// http://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Time Complexity: O(log(n))

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n <= 0) return -1;
        int first = 0, last = n;
        while (first != last)
        {
            int mid = (first + last) / 2;
            if (A[mid] == target)
                return mid;
            if (A[first] <= A[mid])
            {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;
            }
            else
            {
                if (A[mid] < target && target <= A[last - 1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        
        return -1;
    }
};
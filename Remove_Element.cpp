// http://oj.leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        return distance(A, remove(A, A+n, elem));
    }
    
    int removeElement2(int A[], int n, int elem) 
    {
        int index = 0;
        for (int i = 0; i < n; ++i) 
        {
        if (A[i] != elem) 
        {
            A[index++] = A[i];
        }
        }
        return index;
    }
};
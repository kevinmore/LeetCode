// http://oj.leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        return mcss(A, n);
    }
    
private:
    static int mcss(int S[], int n) 
    {
        int i, result, cur_min;
        int *sum = (int*) malloc((n + 1) * sizeof(int));
        sum[0] = 0;
        result = INT_MIN;
        cur_min = sum[0];
        for (i = 1; i <= n; i++) 
        {
            sum[i] = sum[i - 1] + S[i - 1];
        }
        for (i = 1; i <= n; i++) 
        {
            result = max(result, sum[i] - cur_min);
            cur_min = min(cur_min, sum[i]);
        }
        free(sum);
        return result;
    }
};
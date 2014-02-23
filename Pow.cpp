// http://oj.leetcode.com/problems/powx-n/
// x^n = x^{n/2} * x^{n/2} * x^{n\%2}
// Time Complexity: O(logn), Space Complexity: O(1)

class Solution {
public:
    double pow(double x, int n) {
        if (n < 0) return 1.0 / power(x, -n);
        else return power(x, n);
    }

private:
    double power(double x, int n) 
    {
        if (n == 0) return 1;
        double v = power(x, n / 2);
        if (n % 2 == 0) return v * v;
        else return v * v * x;
    }
};
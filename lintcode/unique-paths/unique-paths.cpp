class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        int C = m + n - 2;
        int k = m - 1;

        long long res = 1;

        for (int i=1; i<=k; i++) {
            res = res * (C - k + i) / i;
        }

        return res;
    }
};

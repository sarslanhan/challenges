class Solution {
 public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long zeros = 0ll;

        for (long long i=5; i<=n; i*=5) {
            zeros += n / i;
        }

        return zeros;
    }
};

class Solution {
public:
    int digitCount(int k, int n) {
        bool done = false;
        int count = 0;
        while (!done) {
            int r = n % 10;
            n /= 10;

            if (r == k) count++;

            if (n == 0) done = true;
        }

        return count;
    }
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        int count = 0;
        for (int i=0; i<=n; i++) {
            count += digitCount(k, i);
        }

        return count;
    }
};

class Solution {
    int fibonacci (int n, map<int, int> &cache) {
        if (n < 2) return 0;
        if (n == 2) return 1;

        auto it = cache.find(n);

        if (it == cache.end()) {
            int result = fibonacci(n-1, cache) + fibonacci(n-2, cache);

            cache[n] = result;

            return result;
        } else {
            return (*it).second;
        }
    }
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        map<int, int> cache;

        return fibonacci(n, cache);
    }
};

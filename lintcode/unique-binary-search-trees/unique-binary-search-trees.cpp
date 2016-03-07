class Solution {
    map<int, int> numbers;
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {

        if (n == 1 || n == 0) return 1;

        auto it = numbers.find(n);
        if (it != numbers.end()) return (*it).second;

        int sum = 0;
        for (int i=1; i<=n; i++) {
            sum += numTrees(i-1)*numTrees(n-i);
        }

        numbers[n] = sum;

        return sum;
    }
};

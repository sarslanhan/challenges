class Solution {

    long long fastPower(int a, int b, int n, map<int, long long> &mods) {
        if (n == 0) return 1 % b;
        else if (n == 1) return a % b;

        auto it = mods.find(n);

        if (it != mods.end()) {
            //cout << "found result for " << n << endl;
            return (*it).second;
        }

        //cout << "calculated for " << n << endl;
        long long p = fastPower(a, b, n/2, mods)*fastPower(a, b, n-n/2, mods);
        long long result = p % b;

        mods[n] = result;

        return result;
    }

public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        map<int, long long> mods;

        return fastPower(a, b, n, mods);
    }
};

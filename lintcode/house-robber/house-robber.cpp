#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        vector<long long> stash(A.size(), 0ll);

        stash[0] = A[0];
        stash[1] = MAX(A[0], A[1]);

        for (int i=2; i<A.size(); i++) {
            stash[i] = MAX(stash[i-2]+A[i], stash[i-1]);
        }

        return stash[A.size()-1];
    }
};

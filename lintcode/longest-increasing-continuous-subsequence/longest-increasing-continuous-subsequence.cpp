#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int lics = 0;
        int ldcs = 0;
        int max_lics = 0;
        int max_ldcs = 0;

        for (int i=0; i<A.size(); i++) {
            if (i == 0 || A[i] > A[i-1]) lics++;
            else lics = 1;
            if (i == 0 || A[i] < A[i-1]) ldcs++;
            else ldcs = 1;

            max_lics = MAX(max_lics, lics);
            max_ldcs = MAX(max_ldcs, ldcs);
        }

        return MAX(max_lics, max_ldcs);
    }
};

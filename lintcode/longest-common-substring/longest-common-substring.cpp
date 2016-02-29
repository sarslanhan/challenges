#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        vector<vector<int> > matrix(A.size()+1, vector<int>(B.size()+1, 0));

        int max = 0;
        for (int i=1; i<A.size()+1; i++) {
            for (int j=1; j<B.size()+1; j++) {
                if (A[i-1] == B[j-1]) {
                    matrix[i][j] = matrix[i-1][j-1]+1;
                }

                max = MAX(matrix[i][j], max);
            }
        }

        return max;
    }
};

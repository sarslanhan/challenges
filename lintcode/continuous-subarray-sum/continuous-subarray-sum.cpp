#define MAX(a,b) (a > b ? a : b)

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        if (A.size() == 0) return vector<int>();

        int start = 0, end = 0, sum = A[0];
        int max_start = start, max_end = end, max_sum = sum;

        for (int i = 0; i<A.size(); i++) {
            sum = (A[i], sum + A[i]);

            if (sum < A[i]) {
                start = i;
                end = i;
                sum = A[i];
            } else {
                end = i;
            }

            if (sum > max_sum) {
                max_start = start;
                max_end = end;
                max_sum = sum;
            }
        }

        vector<int> result = { max_start, max_end };

        return result;
    }
};

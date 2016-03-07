class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        int n = 0;
        for (auto &i : A) {
            n = n ^ i;
        }

        return n;
    }
};

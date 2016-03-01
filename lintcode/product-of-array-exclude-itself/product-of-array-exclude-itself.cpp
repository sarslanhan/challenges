#define DEBUG 0
#define PDEBUGVEC(vec) if (DEBUG) { for (auto &i : vec) { cout << i << " "; } cout << endl; }

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> t(nums.size(), 1);

        for (int i=1; i<nums.size(); i++) {
            t[i] = nums[i-1]*t[i-1];
        }

        PDEBUGVEC(t);

        vector<long long> t2(t);

        long long right = 1;
        for (int i=nums.size()-1; i>=0; i--) {
            t2[i] = t[i]*right;
            right *= nums[i];
        }

        PDEBUGVEC(t2);

        return t2;
    }
};

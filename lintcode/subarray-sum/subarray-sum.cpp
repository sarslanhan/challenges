class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        if (nums.size() <= 1) {
            vector<int> result = { 0, 0 };

            return result;
        };

        vector<int> sums(nums);
        sums.insert(sums.begin(), 0);

        for (int i=1; i<sums.size(); i++) {
            sums[i] += sums[i-1];
        }

        for (int i=1; i<sums.size(); i++) {
            if (sums[i] == 0) {
                vector<int> result = { i-1, i-1 };
            }

            for (int j=i; j<sums.size(); j++) {
                if (sums[j] - sums[i-1] == 0) {
                    vector<int> result = { i-1, j-1 };

                    return result;
                }
            }
        }

        return vector<int>();
    }
};

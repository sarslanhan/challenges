class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        int count = 1;
        int n = nums[0];

        for (int i=1; i<nums.size(); i++) {
            if (count == 0) {
                count = 1;
                n = nums[i];
                continue;
            }
            if (nums[i] != n) {
                count--;
            } else {
                count++;
            }
        }

        return n;
    }
};

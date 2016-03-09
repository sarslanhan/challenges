class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        if (nums.size() < 2) return nums;

        int tail = nums.size() - 2;

        while (tail >= 0) {
            if (nums[tail] < nums[tail+1]) break;

            tail--;
        }

        if (tail < 0) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        int swap = nums.size() - 1;

        while (swap > tail) {
            if (nums[swap] > nums[tail]) break;

            swap--;
        }

        int temp = nums[swap];
        nums[swap] = nums[tail];
        nums[tail] = temp;

        reverse(nums.begin()+tail+1, nums.end());

        return nums;
    }
};

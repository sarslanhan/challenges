class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > result;

        for (int i=0; i<nums.size()-2; i++) {

            if (i != 0 && nums[i] == nums[i-1]) continue;

            int target = -1 * nums[i];

            int start = i+1;
            int end = nums.size()-1;

            while (start < end) {


                int diff = target - (nums[start] + nums[end]);

                if (diff == 0) {

                    vector<int> triple = { nums[i], nums[start], nums[end] };

                    result.push_back(triple);
                    start++;
                    end--;

                    while (start < end && nums[start] == nums[start-1]) start++;

                    while (start < end && nums[end] == nums[end+1]) end--;

                } else if (diff < 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }

        return result;
    }
};

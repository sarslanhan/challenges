class Solution {
    int abs(int x) {
        return x > 0 ? x : (-1 * x);
    }
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {

        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;
        int a, b, c;

        for(int i=0; i<nums.size()-2; i++) {
            int start = i+1;
            int end = nums.size()-1;

            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int diff = this->abs(target - sum);

                if (min_diff >= diff) {
                    a = i;
                    b = start;
                    c = end;
                    min_diff = diff;
                }

                if (target > sum) {
                    start++;
                } else {
                    end--;
                }
            }
        }

        return nums[a]+nums[b]+nums[c];
    }
};

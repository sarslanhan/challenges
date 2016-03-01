class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> diffs;

        for (int i=0; i<nums.size(); i++) {
            diffs[target-nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++) {
            auto it = diffs.find(nums[i]);
            if (it != diffs.end() && (*it).second != i) {
                vector<int> result = { i+1, (*it).second+1 };

                return result;
            }
        }

        return vector<int>();
    }
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 1
#define PDEBUG(output) if (DEBUG) cout << output
#define PDEBUGLN(output) PDEBUG(output << endl)
#define FOR(i, start, end) for (int i=start; i<end; i++)
#define PDEBUGVEC(vec) { FOR(_i, 0, vec.size()) { PDEBUG(vec[_i] << ' '); } PDEBUG(endl); }
#define PDEBUGVEC2D(vec) { FOR(_j, 0, vec.size()) { PDEBUGVEC(vec[_j]); } }

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;

        if (nums.size() < 4) return result;

        sort(nums.begin(), nums.end());

        FOR(i, 0, nums.size()-3) {
            auto sum = target - nums[i];

            FOR(j, i+1, nums.size()-2) {
                auto sum2 = sum - nums[j];

                auto start = j+1;
                auto end = nums.size()-1;

                while (start < end) {
                    auto sum3 = nums[start] + nums[end];
                    
                    if (sum3 == sum2) {
                        vector<int> quadruplet = { nums[i], nums[j], nums[start], nums[end] };
                        result.push_back(quadruplet);

                        while (start < end && nums[start] == quadruplet[2]) start++;
                        while (start < end && nums[end] == quadruplet[3]) end--;
                    } else if (sum3 < sum2) {
                        start++;
                    } else {
                        end--;
                    }
                }

                while (j+1 < nums.size() && nums[j] == nums[j+1]) j++;
            }

            while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = { 1, 0, -1, 0, -2, 2 };

    PDEBUG("TEST CASE ");PDEBUGVEC(nums);

    auto result = s.fourSum(nums, 0);

    PDEBUGVEC2D(result);

    vector<int> nums2 = { -1, 0, 1, 2, -1, -4 };

    PDEBUG("TEST CASE ");PDEBUGVEC(nums2);

    auto result2 = s.fourSum(nums2, -1);

    PDEBUGVEC2D(result2);

    vector<int> nums3 = { -3, -2, -1, 0, 0, 1, 2, 3 };

    PDEBUG("TEST CASE ");PDEBUGVEC(nums3);

    auto result3 = s.fourSum(nums3, 0);

    PDEBUGVEC2D(result3);
}

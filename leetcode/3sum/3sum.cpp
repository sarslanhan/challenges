#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 1
#define PDEBUG(output) if (DEBUG) cout << output;
#define PDEBUGLN(output) PDEBUG(output << endl);
#define PDEBUGVEC(vec) { for(size_t _i=0; _i<vec.size(); _i++) { PDEBUG(vec[_i] << " ");  } PDEBUG(endl); }
#define PDEBUGVEC2D(vec) { for(size_t _j=0; _j<vec.size(); _j++) { PDEBUGVEC(vec[_j]);  } }

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int> >();

        sort(nums.begin(), nums.end());

        vector<vector<int> > result;

        for (size_t i=0; i<nums.size()-2; i++) {

            if (i == 0 || nums[i] > nums[i-1]) {
                int sum = nums[i] * -1;

                size_t start = i + 1;
                size_t end = nums.size() - 1;

                while (start < end) {
                    if (nums[start] + nums[end] == sum) {
                        int r[3] = { nums[i], nums[start], nums[end]};

                        result.push_back(vector<int>(&r[0], &r[0] + 3));

                        while (start < end && nums[start] == r[1]) start++;

                        while (start < end && nums[end] == r[2]) end--;
                    } else if (nums[start] + nums[end] < sum) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    int a[6] = { -1, 0, 1, 2, -1, -4 };

    vector<int> nums(&a[0], &a[0] + 6);

    PDEBUGVEC2D(s.threeSum(nums));
}

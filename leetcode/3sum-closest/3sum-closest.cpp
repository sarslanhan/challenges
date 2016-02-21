#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 1
#define ABS(a) (a >= 0 ? a : (-1*a))
#define CLOSEST(a, b, target) (ABS((target - a)) > ABS((target - b)) ? b : a)
#define PDEBUG(output) if (DEBUG) cout << output
#define PDEBUGLN(output) PDEBUG(output << endl)
#define PDEBUGVEC(vec) { for(size_t _i=0; _i<vec.size(); _i++) { PDEBUG(vec[_i] << " ");  } PDEBUG(endl); }
#define PDEBUGVEC2D(vec) { for(size_t _j=0; _j<vec.size(); _j++) { PDEBUGVEC(vec[_j]);  } }

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return INT_MAX;

        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        PDEBUGLN("closest sum: " << closest);

        for (size_t i=0; i<nums.size()-2; i++) {

            int sum = target - nums[i];

            size_t start = i + 1;
            size_t end = nums.size() - 1;

            while (start < end) {
                int diff = nums[start] + nums[end];

                PDEBUGLN("current sum: " << diff + nums[i] << " - " << nums[i] << " " << nums[start] << " " << nums[end] << " | " << ABS(target - (diff + nums[i])) << " - " << ABS(target - closest));

                closest = CLOSEST((diff + nums[i]), closest, target);

                PDEBUGLN("closest sum: " << closest << " - " << nums[i] << " " << nums[start] << " " << nums[end]);

                if (diff == sum) {
                    return target;
                } else if (diff < sum) {
                    start++;
                } else {
                    end--;
                }
            }
        }

        return closest;
    }
};

int main() {
    Solution s;

    int a[4] = { -1, 2, 1, -4 };

    vector<int> nums(&a[0], &a[0] + 4);

    PDEBUGLN(s.threeSumClosest(nums, 1));

    int b[4] = { 1, 1, 1, 0 };

    vector<int> nums2(&b[0], &b[0] + 4);

    PDEBUGLN(s.threeSumClosest(nums2, 100));

    int c[4] = { 1, 1, 1, 0 };

    vector<int> nums3(&c[0], &c[0] + 4);

    PDEBUGLN(s.threeSumClosest(nums3, -100));
}

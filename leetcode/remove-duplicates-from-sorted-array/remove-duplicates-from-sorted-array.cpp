#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1
#define PDEBUG(output) if (DEBUG) cout << output;
#define PDEBUGLN(output) PDEBUG(output << endl);
#define FOR(i, size) for (int i=0; i<size; i++)
#define FORREV(i, size) for (int i=size-1; i>=0; i--)
#define PDEBUGVEC(vec) { FOR(i, vec.size()) { PDEBUG(vec[i] << ' '); } PDEBUG(endl) }

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        FORREV(idx, nums.size()) {
            int cur = idx-1;
            int remove = 0;
            while (cur >= 0 && nums[cur] == nums[idx]) {
                remove++;
                cur--;
            }

            if (remove) {
                nums.erase(nums.begin()+idx-remove, nums.begin()+idx);

                PDEBUGLN("removing elements between: " << (idx-remove) << ',' << idx);

                size -= remove;
                idx -= remove-1;
            }

            PDEBUGVEC(nums);
        }

        return size;
    }
};

int main() {
    Solution s;

    int a[] = { 1, 1, 2, 2, 3 };
    vector<int> nums(&a[0], &a[0]+5);

    PDEBUGLN("result: " << s.removeDuplicates(nums));

    int a2[] = { 1, 1, 1, 1 };
    vector<int> nums2(&a2[0], &a2[0]+4);

    PDEBUGLN("result: " << s.removeDuplicates(nums2));

    PDEBUGVEC(nums2);
}

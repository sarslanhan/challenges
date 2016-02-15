#include <vector>
#include <map>
#include <iostream>

#define FOR(i, length) for(int i=0; i<length; i++)
#define PVECTOR(vec) { FOR(i, vec.size()) { cout << vec[i] << " "; } cout << endl; }

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indices;

        FOR(i, nums.size()) {
            indices.insert(pair<int, int>(nums[i], i));
        }

        map<int, int>::iterator it;

        FOR(i, nums.size()) {
            it = indices.find(target-nums[i]);

            if (it != indices.end() && it->second != i) {
                vector<int> result;

                result.push_back(i);
                result.push_back(it->second);

                return result;
            }
        }

        return vector<int>();
    }
};

int main() {
    Solution s;

    int nums[] = {11, 2, 7, 15};
    int target = 9;

    vector<int> a(&nums[0], &nums[0] + 4);

    PVECTOR(s.twoSum(a, target));

    int nums2[] = {3, 2, 4};
    target = 6;

    vector<int> b(&nums2[0], &nums2[0]+3);

    PVECTOR(s.twoSum(b, target));
}

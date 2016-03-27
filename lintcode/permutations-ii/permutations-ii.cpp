typedef vector<vector<int>> LLI;
typedef vector<int> LI;

class Solution {
    void print(LI &vec) {
        for (auto &i : vec) {
            cout << i << " ";
        }

        cout << endl;
    }
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    LLI permuteUnique(LI &nums) {
        if (nums.size() == 0) return LLI();
        else if (nums.size() < 2) return LLI { nums };

        sort(nums.begin(), nums.end());

        LLI permutations = { nums };

        while (true) {
            int tail = nums.size() - 2;
            while (tail >= 0) {
                if (nums[tail] < nums[tail+1]) break;

                tail--;
            }

            if (tail <= 0) return permutations;

            int swap = nums.size() - 1;
            while (swap < tail) {
                if (nums[swap] > nums[tail] && nums[swap] != nums[swap-1]) break;

                swap--;
            }

            if (swap < tail) return permutations;

            int temp = nums[swap];
            nums[swap] = nums[tail];
            nums[tail] = temp;

            reverse(nums.begin()+tail+1, nums.end());

            print(nums);

            permutations.push_back(nums);
        }

        return permutations;
    }
};

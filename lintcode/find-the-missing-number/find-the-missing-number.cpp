class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        long long sum = 0;
        for (int &i : nums) {
            sum += i;
        }

        int n = nums.size();
        long long expected = (n * (n+1))/2;

        return expected - sum;
    }
};

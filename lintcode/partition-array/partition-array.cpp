class Solution {
private:
    void swap(vector<int> &nums, int i, int j) {
        if (i == j) return;

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    int partitionArray(vector<int> &nums, int k) {
        int partition_length = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < k) {
                this->swap(nums, i, partition_length);
                partition_length++;
            }
        }

        return partition_length;
    }
};

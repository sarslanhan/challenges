class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int length = nums.size();
        int removed = 0;
        for (int i=0; i<length-1;) {
            //cout << removed << " " << (i+removed+1) << " - " << nums[i] << " " << nums[i+removed+1] << endl;

            while (i+removed+1 < length && nums[i] == nums[i+removed+1]) {
                removed++;
            }

            if (i+removed+1 < length)
                swap(nums[i+1], nums[i+removed+1]);
            i++;
        }

        return length-removed;
    }
};

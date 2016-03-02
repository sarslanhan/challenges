class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        int start = 0;
        int end = array.size();
        int mid = 0;

        while (start < end) {
            int old = mid;
            mid = start + (end-start)/2;

            if (old == mid) return -1;

            if (array[mid] == target) {
                while (mid > 0 && array[mid] == array[mid-1]) mid--;

                return mid;
            }
            else if (array[mid] < target) start = mid;
            else end = mid;
        }

        return -1;
    }
};

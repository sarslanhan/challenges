class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int start = 0;
        int end = A.size();
        int mid = 0;

        while (start < end) {
            int old = mid;

            mid = start + (end - start)/2;

            if (old == mid)
                return A[mid] == target ? mid : mid + 1;

            //cout << mid << " " << start << " " << end << endl;

            if (A[mid] == target) return mid;
            else if (A[mid] < target) start = mid;
            else end = mid;
        }

        return mid;
    }
};

class Solution {
private:
    int search_(vector<int> &A, int target, int start, int end) {
        if (start >= end) return false;

        int mid = start + (end - start)/2;

        if (A[mid] == target) return true;
        else if (A[mid] < target) start = mid+1;
        else end = mid;

        return search_(A, target, start, end);
    }
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        for (auto &row : matrix) {
            if (search_(row, target, 0, row.size())) return true;
        }

        return false;
    }
};

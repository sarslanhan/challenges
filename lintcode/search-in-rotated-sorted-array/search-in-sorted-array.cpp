class Solution {
private:
    int search_(vector<int> &A, int target, int start, int end) {
        if (start >= end) return -1;

        int mid = start + (end - start)/2;

        //cout << start << " " << mid << " " << end << endl;

        if (A[mid] == target) return mid;

        if (A[start] <= A[end-1]) {
            if (A[mid] > target) end = mid;
            else start = mid+1;

            return search_(A, target, start, end);
        }

        int partial = search_(A, target, start, mid);
        if (partial >= 0) return partial;

        return search_(A, target, mid+1, end);
    }
public:
    int search(vector<int> &A, int target) {
        return search_(A, target, 0, A.size());
    }
};

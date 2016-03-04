class Solution {
private:
    int search_(vector<int> &A, int target, int start, int end) {
        if (start >= end) return -1;

        int mid = start + (end - start)/2;

        if (A[mid] == target) return mid;
        else if (A[mid] < target) start = mid+1;
        else end = mid;

        return search_(A, target, start, end);
    }
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int idx = search_(A, target, 0, A.size());

        if (idx == -1) return { -1, -1 };

        int start = idx;
        int end = idx;

        while (start > 0 && A[start-1] == A[idx]) start--;
        while (end < A.size()-1 && A[end+1] == A[idx]) end++;

        return { start, end };
    }
};

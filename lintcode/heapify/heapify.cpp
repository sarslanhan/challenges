#include <vector>
#include <iostream>

using namespace std;

#define DEBUG 0
#define PDEBUG(output) if (DEBUG) cout << output
#define PDEBUGVEC(vec) { for (size_t _i=0; _i<vec.size(); _i++) PDEBUG(vec[_i] << ' '); PDEBUG(endl); }
#define MIN(vec, a,b) (vec[a] > vec[b] ? b : a)
#define MIN3(vec, a,b,c) (MIN(vec, MIN(vec, a, b), c))

class Solution {
private:
    inline size_t left_child_p(size_t i) {
        return i*2+1;
    }

    inline size_t right_child_p(size_t i) {
        return i*2+2;
    }

    inline void swap(vector<int> &A, size_t i, size_t j) {
        PDEBUG("swapping " << A[i] << " and " << A[j] << endl);
        size_t temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    inline void min_heapify_node(vector<int> &A, size_t p) {
        size_t min_p = p;
        size_t left_p = left_child_p(p);
        size_t right_p = right_child_p(p);
        if (left_p < A.size() && right_p < A.size()) {
            PDEBUG("heapifying nodes: " << A[p] << " " << A[left_p] << " " << A[right_p] << endl);
            min_p = MIN3(A, p, left_p, right_p);
        } else if (left_p < A.size()) {
            PDEBUG("heapifying nodes: " << A[p] << " " << A[left_p] << endl);
            min_p = MIN(A, p, left_p);
        } else if (right_p < A.size()) {
            PDEBUG("heapifying nodes: " << A[p] << " " << A[right_p] << endl);
            min_p = MIN(A, p, right_p);
        } else {
            PDEBUG("heapifying nodes: " << A[p] << endl);
            min_p = p;
        }

        if (min_p == p) return;

        swap(A, min_p, p);
        min_heapify_node(A, min_p);
    }
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i=(A.size()/2); i>=0; i--) {
            PDEBUG("pass no: " << i << endl);
            PDEBUGVEC(A);
            min_heapify_node(A, i);
        }
    }
};


int main() {
    Solution s;
    vector<int> tc = { 3, 2, 1, 4, 5 };
    PDEBUG("testcase" << endl);
    PDEBUGVEC(tc);
    s.heapify(tc);
    PDEBUGVEC(tc);

    vector<int> tc2 = { 42,30,27,93,8,34,47,64,82,76,70,79,23,5,67,9,97,29,7,61,73,3,44,85,51,49,90,59,38,55,39,62,54,81,26,50,22,71,52,41,77,32,2,96,84,20,48,17,87,94,12,13,89,24,6,74,69,78,65,35,15,28,25,16,33,63 };
    PDEBUG("testcase" << endl);
    PDEBUGVEC(tc2);
    s.heapify(tc2);
    PDEBUGVEC(tc2);
}

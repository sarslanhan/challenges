class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        for (int i=0; i<A.size(); i++) {
            if (A[i] > 0 && A[i] <= A.size() && A[A[i]-1] != A[i]) {
                swap(A[i], A[A[i]-1]);
                i--;
            }
        }

        for (int i=0; i<A.size(); i++) {
            if (A[i] != i+1) return i+1;
        }

        return A.size()+1;

        /*int min = INT_MAX;
        for (auto &i : A) {
            if (i <= 0) continue;

            if (i > 0 && i < min) {
                min = i;
            }
        }

        if (min == INT_MAX) return 1;
        if (min != 1) return min-1;

        int i;

        for (i=0; i<A.size(); i++) {
            if (i > A.size() || i <= 0) continue;

            if (i != A[i]-1) this->swap(A, i, A[i]-1);
        }

        for (i=0; i<A.size(); i++) {
            //cout << i << " " << A[i] << endl;
            if (i != A[i]-1) {
                if (A[i]-1 >= 0 && A[i]-1 < A.size() && A[i] != A[A[i]-1]) {
                    return i;
                } else {
                    return i+1;
                }
            }
        }

        return i+1;*/
    }
};

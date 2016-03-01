class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        for (int i=m-1; i>=0; i--) {
            A[i+n] = A[i];
        }

        int i=0, j=0, k=0;

        for (; i<m && j<n;k++) {
            if (A[i+n] < B[j]) {
                A[k] = A[i+n];
                i++;
            } else {
                A[k] = B[j];
                j++;
            }
        }

        for (; i<m; i++, k++) A[k] = A[i+n];

        for (; j<n; j++, k++) A[k] = B[j];
    }
};

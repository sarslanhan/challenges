class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int length = A.size();

        for (int i=0; i<length; i++) {
            if (A[i] == elem) {
                A[i] = A[length-1];
                i--;
                length--;
            }
        }

        return length;
    }
};

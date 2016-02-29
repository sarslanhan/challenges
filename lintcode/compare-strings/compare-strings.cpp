class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        if (B.size() > A.size()) return false;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        for (auto &c_b : B) {
            bool found = false;
            for (auto &c_a : A) {
                if (c_a == c_b) {
                    found = true;
                    c_a = '$';
                    break;
                }
            }

            if (!found) return false;
        }

        return true;
    }
};

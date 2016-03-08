#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define CHAR_TO_INT(c) (c - '0')

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        if (A.size() <= k) return "";
        else if (k == 0) return A;

        for (; k>0; k--) {
            int i;
            bool removed = false;
            for (i=1; i < A.size(); i++) {
                if (A[i] >= A[i-1]) {
                    continue;
                }

                removed = true;
                A.erase(i-1, 1);
                break;
            }
            if (!removed && i == A.size()) A.erase(A.size()-1,1);
        }

        while (!A.empty() && A.front() == '0')
            A.erase(0, 1);

        return A;
    }
};

int main() {
    Solution s;

    cout << "solution for " << "90249: " << endl;
    cout << s.DeleteDigits("90249", 2) << endl;

    cout << "solution for " << "178542: " << endl;
    cout << s.DeleteDigits("178542", 4) << endl;

    cout << "solution for " << "254193: " << endl;
    cout << s.DeleteDigits("254193", 1) << endl;

    cout << "solution for " << "123456789: " << endl;
    cout << s.DeleteDigits("123456789", 1) << endl;
}

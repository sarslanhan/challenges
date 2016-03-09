#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
    bool canJump(vector<int> &A, vector<int> &cache, int current) {
        if (current == A.size()-1) return true;
        else if (current >= A.size()) return false;

        int jump = A[current];

        for (int i=1; i<=jump; i++) {
            if (cache[current+i] == -1 && canJump(A, cache, current+i)) return true;

            cache[current+i] = 0;
        }

        cache[current] = 0;

        return false;
    }
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        vector<int> cache(A.size(), -1);

        return canJump(A, cache, 0);
    }
};


int main() {
    Solution s;

    cout << s.canJump(vector<int>{2,3,1,1,4}) << endl;
    cout << s.canJump(vector<int>{3,2,1,0,4}) << endl;
}

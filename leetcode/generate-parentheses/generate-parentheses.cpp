#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define DEBUG 1
#define PDEBUG(output) if (DEBUG) cout << output;
#define PDEBUGLN(output) PDEBUG(output << endl);
#define PDEBUGVEC(vec) { for(size_t _i=0; _i<vec.size(); _i++) { PDEBUG(vec[_i] << " ");  } PDEBUG(endl); }

class Solution {
private:
    void backtrack(vector<string> &result, const string &cur, int open, int closed, int max) {
        PDEBUGLN(cur << " open: " << open << " closed: " << closed);
        if (cur.size() == 2*max) {
            result.push_back(cur);
            return;
        }

        if (open < max) backtrack(result, cur + '(', open + 1, closed, max);
        if (closed < open) backtrack(result, cur + ')', open, closed + 1, max);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(result, "", 0, 0, n);

        return result;
    }
};

int main() {
    Solution s;

    const vector<string> &result = s.generateParenthesis(3);

    PDEBUGVEC(result);
}

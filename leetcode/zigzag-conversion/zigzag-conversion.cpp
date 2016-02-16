#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define DEBUG 1
#define PDEBUG(output) if (DEBUG) cout << output
#define PDEBUGLN(output) PDEBUG(output << endl)
#define PSTRVECLN(vec) { FOR(i, vec.size()) { PDEBUG(i << ':' << vec[i] << ' '); } PDEBUG(endl); }
#define FOR(i, size) for(int i=0; i<size; i++)

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 1) return s;

        vector<string> rows(numRows, string());

        bool down = true;
        int r = 0;

        FOR(i, s.size()) {
            rows[r].push_back(s[i]);

            PDEBUGLN(s[i] << ':' << r << '-' << down);

            if(down) r++;
            else r--;

            if (r == 0 || r == numRows-1) down = !down;

            PSTRVECLN(rows);
        }

        string result;

        FOR(i, numRows) {
            result += rows[i];
        }

        return result;
    }
};

int main() {
    Solution s;

    PDEBUGLN(s.convert("PAYPALISHIRING", 3));
}

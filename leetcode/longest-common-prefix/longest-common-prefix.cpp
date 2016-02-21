#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG 1
#define PDEBUG(output) if (DEBUG) cout << output;
#define PDEBUGLN(output) PDEBUG(output << endl);
#define PDEBUGVEC(vec) { for(size_t _i=0; _i<vec.size(); _i++) { PDEBUG(vec[_i] << " ");  } PDEBUG(endl); }
#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        PDEBUGVEC(strs);

        size_t length = 0;
        size_t max_length = 0;

        for(size_t i=0; i < strs.size(); i++) {
            max_length = MAX(max_length, strs[i].size());
        }

        for(size_t i=0; i < max_length; i++) {
            char c = strs[0][i];
            bool failed = false;
            for (size_t j=1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    failed = true;
                    break;
                };
            }

            if (failed) break;

            length++;
        }

        return string(strs[0], 0, length);
    }
};

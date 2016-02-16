#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define DEBUG 1
#define INDICE_LENGTH(a) (a[1] - a[0] + 1)
#define MAX(a, b) (INDICE_LENGTH(a) > INDICE_LENGTH(b) ? a : b)
#define FOR(i, size) for (int i=0; i<size; i++)
#define FOR2(i, start, size) for (int i=start; i<size; i++)
#define PDEBUG(output) if (DEBUG) cout << output
#define PDEBUGLN(output) PDEBUG(output << endl)

class Solution {
public:

    vector<int> expand(string &s, int i, int j) {
        bool revert = false;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            PDEBUGLN(s << "-" << i << "," << j << " - " << string(s, i, j-i+1));
            revert = true;
            i--;
            j++;
        }

        if (revert) {
            i++;
            j--;
        } else {
            i = 0;
            j = 0;
        }

        PDEBUGLN("after revert: " << s << "-" << i << "," << j << " - " << string(s, i, j-i+1));

        int a[] = {i, j};

        vector<int> indices(&a[0], &a[0]+2);

        return indices;
    }

    string longestPalindrome(string s) {
        if (s.size () < 2) return s;
        else if (s.size() == 2 && s[0] == s[1]) return s;

        int a[] = {0,0};
        vector<int> longest(&a[0], &a[0]+2);

        FOR2(i, 0, s.size() - 1) {
            longest = MAX(longest, expand(s, i-1, i+1));
            longest = MAX(longest, expand(s, i, i+1));
            PDEBUGLN("current longest: " << longest[0] << "," << longest[1] << " - " << string(s, longest[0], longest[1]-longest[0]+1));
        }

        return string(s, longest[0], longest[1]-longest[0]+1);
    }
};

int main() {
    Solution s;

    PDEBUGLN(s.longestPalindrome("arraba"));
    PDEBUGLN(s.longestPalindrome("araba"));
    PDEBUGLN(s.longestPalindrome("bb"));
    PDEBUGLN(s.longestPalindrome("abb"));
    PDEBUGLN(s.longestPalindrome("ccd"));
}

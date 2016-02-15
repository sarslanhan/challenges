#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define DEBUG 0
#define MAX(a, b) (a > b ? a : b)
#define FOR(i, size) for (int i=0; i<size; i++)
#define PDEBUG(output) if (DEBUG) cout << output
#define PDEBUGLN(output) PDEBUG(output << endl)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(256, -1);
        int max = 0;
        int start = 0;

        FOR(i, s.size()) {
            PDEBUGLN(s[i] << '-' << chars[s[i]] << '-' << start << '-' << max);
            start = MAX(chars[s[i]]+1, start);
            chars[s[i]] = i;

            max = MAX(max, i - start + 1);
        }

        PDEBUGLN("Longest non repeating substring length: " << max);

        return max;
    }
};

int main() {
    Solution s;

    s.lengthOfLongestSubstring("abcabcbb");
}

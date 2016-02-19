#include <iostream>

using namespace std;

#define DEBUG 1
#define PDEBUGLN(output) if (DEBUG) cout << output << endl

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int t = x;
        int r = 0;

        // no need to consider the overflow case since it will
        // be a different number than x anyway
        while (x != 0) {
            r += x % 10;
            x /= 10;

            if (x) r *= 10;
        }

        PDEBUGLN("reverse: " << r);

        return r == t;
    }
};

int main() {
    Solution s;

    PDEBUGLN("123: " << endl << s.isPalindrome(123));
    PDEBUGLN("121: " << endl << s.isPalindrome(121));
}

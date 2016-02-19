#include <iostream>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

#define DEBUG 1
#define PDEBUGLN(output) if (DEBUG) cout << output << endl

class Solution {
private:
    int safeAddition(int a, int b) {
        int x = a + b;

        if (((b > 0) && (a > INT_MAX - b)) /* `a + b` would overflow */
            || ((b < 0) && (a < INT_MIN - b))) /* `a + b` would underflow */
            throw "INT_OVERFLOW";

        PDEBUGLN(a << '+' << b << '=' << x);

        return x;
    }

    int safeMultiplication (int a, int b) {
        int x = a * b;

        if (a != 0 && x / a != b) throw "INT_OVERFLOW";

        PDEBUGLN(a << '8' << b << '=' << x);

        return x;
    }
public:
    int myAtoi(string str) {
        if (!str.size()) return 0;


        bool negative = false;
        bool started = false;
        int x = 0;

        try {
            for (int i = (negative ? 1 : 0); i < str.size(); i++) {
                char c = str[i];

                PDEBUGLN("1." << c << ": " << x);
                if (c >= '0' && c <= '9') {
                    started = true;
                    x = safeMultiplication(x, 10);

                    x = safeAddition(x, c - '0');
                } else if (!started && isspace(c)) {

                } else if (!started && x == 0 && c == '+') {
                    started = true;
                } else if (!started && x == 0 && c == '-') {
                    negative = true;
                    started = true;
                } else {
                    break;
                }
            }

            if (negative) x = safeMultiplication(x, -1);

        } catch (const char *message) {
            PDEBUGLN("an " << message << " occurred while parsing " << str);
            x = negative ? INT_MIN : INT_MAX;
        }


        return x;
    }
};

int main() {
    Solution s;

    PDEBUGLN("123:" << endl << s.myAtoi("123"));
    PDEBUGLN("-123:" << endl << s.myAtoi("-123"));
    PDEBUGLN("   123:" << endl << s.myAtoi("   123"));
    PDEBUGLN("   -123:" << endl << s.myAtoi("   -123"));
    PDEBUGLN("   -1a23:" << endl << s.myAtoi("   -1a23"));
    PDEBUGLN("+-2:" << endl << s.myAtoi("+-2"));
    PDEBUGLN("+1:" << endl << s.myAtoi("+1"));
    PDEBUGLN("    010:" << endl << s.myAtoi("    010"));
    PDEBUGLN("2147483648:" << endl << s.myAtoi("2147483648"));
}

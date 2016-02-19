#include <iostream>
#include <limits>

using namespace std;

#define DEBUG 1
#define PDEBUGLN(output) if (DEBUG) cout << output << endl

class Solution {
private:
    int safeAddition(int a, int b) {
        int x = a + b;

        if (x - a != b) throw "INT_OVERFLOW";

        PDEBUGLN(a << '+' << b << '=' << x);

        return x;
    }

    int safeMultiplication(int a, int b) {
        int x = a * b;

        if (a != 0 && x / a != b) throw "INT_OVERFLOW";

        PDEBUGLN(a << '*' << b << '=' << x);

        return x;
    }
public:
    int reverse(int x) {
        if (!x) return x;

        int reverse = 0;

        try {
            while (true) {
                reverse = this->safeAddition(reverse, x % 10);

                x /= 10;

                if (!x) break;

                reverse = this->safeMultiplication(reverse, 10);
            }
        } catch (const char* message) {
            PDEBUGLN("caught an exception: " << message);
            reverse = 0;
        }

        return reverse;
    }
};

int main() {
    Solution s;

    PDEBUGLN(123 << ": " << endl << s.reverse(123));
    PDEBUGLN(-123 << ": " << endl << s.reverse(-123));
    PDEBUGLN(numeric_limits<int>::min() << ": " << endl << s.reverse(numeric_limits<int>::min()));
    PDEBUGLN(numeric_limits<int>::max() << ": " << endl << s.reverse(numeric_limits<int>::max()));
    PDEBUGLN(10 << ": " << endl << s.reverse(10));
    PDEBUGLN(900000 << ": " << endl << s.reverse(900000));
    PDEBUGLN(-2143847412 << ": " << endl << s.reverse(-2143847412));
}

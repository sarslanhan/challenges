#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        stringstream ss;
        stringstream ss_out;

        ss << n;

        double p;

        ss >> p;

        // exponent
        int i = 1;
        while (i < p) {
            i *= 2;
        }

        if (i > p) i /= 2;

        if (i == 0) ss_out << '0';

        while (p >= 1 || i > 0) {
            if (p >= i) {
                ss_out << '1';
                p -= i;
            } else {
                ss_out << '0';
            }
            i /= 2;
        }

        if (p > 0) ss_out << '.';

        // mantissa
        int fraction_length = 0;
        double f = 0.5;
        while (p > 0) {
            if (p >= f) {
                p -= f;
                ss_out << '1';
            } else {
                ss_out << '0';
            }

            f /= 2;
            fraction_length++;

            if (fraction_length > 24) return "ERROR";
        }

        return ss_out.str();
    }
};

int main() {
    Solution s;

    cout << s.binaryRepresentation("3.72") << endl;
    cout << s.binaryRepresentation("3.5") << endl;
    cout << s.binaryRepresentation("2.0") << endl;
    cout << s.binaryRepresentation("0.5") << endl;
    cout << s.binaryRepresentation("28187281.128121212121") << endl;
}

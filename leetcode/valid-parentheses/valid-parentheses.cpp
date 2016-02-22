#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define DEBUG 1
#define PDEBUGLN(output) if (DEBUG) cout << output << endl

class Solution {
public:
    bool isValid(string str) {
        if (str.empty()) return true;

        stack<char> s;

        for (int i=0; i<str.size(); i++) {
            char c = str[i];

            if (c == '{' || c == '(' || c == '[') {
                s.push(c);
            } else {
                char top = s.empty() ? 0 : s.top();
                s.pop();

                if ((c == '}' && top != '{')
                    || (c == ')' && top != '(')
                    || (c == ']' && top != '[')) return false;
            }
        }

        return s.empty();
    }
};

int main() {
    Solution s;

    PDEBUGLN(s.isValid("()"));
    PDEBUGLN(s.isValid("()[]{}"));
    PDEBUGLN(s.isValid("(]"));
    PDEBUGLN(s.isValid("([)]"));
}

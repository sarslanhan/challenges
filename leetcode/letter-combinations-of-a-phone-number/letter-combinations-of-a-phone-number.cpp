#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG 1
#define PDEBUG(output) if (DEBUG) cout << output
#define PDEBUGLN(output) PDEBUG(output << endl)
#define PDEBUGVEC(vec) { for(size_t _i=0; _i<vec.size(); _i++) { PDEBUG(vec[_i] << " ");  } PDEBUG(endl); }
#define CHAR_TO_INT(c) (c - '0')

class Solution {
private:
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();

        static const vector<string> map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        vector<string> result = { "" };

        for (size_t i=0; i<digits.size(); i++) {
            int num = CHAR_TO_INT(digits[i]);

            const string &candidate = map[num];

            if (candidate.empty()) continue;

            vector<string> temp;

            for (size_t j=0; j<candidate.size(); j++) {
                for (size_t k=0; k<result.size(); k++) {
                    temp.push_back(result[k] + candidate[j]);
                }
            }

            result.swap(temp);

            PDEBUGLN("candidate list for index: " << i);
            PDEBUGVEC(result);
        }

        return result;
    }
};

/**
 * Compile it with: g++ -std=c++11 letter-combinations-of-a-phone-number.cpp && ./a.out
 */
int main() {
    Solution s;

    s.letterCombinations("23");
}

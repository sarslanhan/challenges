#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
private:
    map<string, int> counts;
public:
    void insert(string &s) {
        auto it = counts.find(s);

        if (it == counts.end()) {
            counts[s] = 1;
        } else {
            counts[s] = (*it).second+1;
        }
    }

    int query(string &s) {
        auto it = counts.find(s);

        if (it != counts.end()) {
            return (*it).second;
        } else {
            return 0;
        }
    }
};

int main() {

    int N, Q;

    Solution s;

    cin >> N;

    for (int i=0; i<N; i++) {
        string str;

        cin >> str;

        s.insert(str);
    }

    cin >> Q;

    for (int i=0; i<Q; i++) {
        string str;

        cin >> str;

        cout << s.query(str) << endl;
    }

    return 0;
}

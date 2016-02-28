#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class DynamicArray {
private:
    int N;
    int Q;
    int lastans;
    map<int, vector<int> > collection;

    int index_(int x) {
        return (x^this->lastans) % N;
    }
public:

    DynamicArray(int _N, int _Q) {
        this->N = _N;
        this->Q = _Q;
        this->lastans = 0;
    }

    void insert(int x, int y) {
        int idx = this->index_(x);

        auto it = this->collection.find(idx);

        if (it != this->collection.end()) {
            (*it).second.push_back(y);
        } else {
            this->collection[idx] = vector<int>(1, y);
        }
    }

    int query(int x, int y) {
        int idx = this->index_(x);

        auto it = this->collection.find(idx);

        if (it != this->collection.end()) {
            vector<int> &a = (*it).second;

            lastans = a[y % a.size()];

            return lastans;
        } else {
            return -1;
        }
    }
};

int main() {
    int N, Q;

    cin >> N >> Q;

    DynamicArray da(N, Q);

    for (int i = 0; i<Q; i++) {
        int command, x, y;

        cin >> command >> x >> y;

        if (command == 1) {
            da.insert(x, y);
        } else {
            cout << da.query(x, y) << endl;
        }
    }
}

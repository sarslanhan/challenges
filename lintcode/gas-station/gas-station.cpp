#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0;
        int current = start;
        int g = 0;
        int moves = 0;

        do {
            int before = (start == 0) ? gas.size()-1 : start-1;
            while (g < 0 && before != start) {
                g -= gas[start] - cost[start];
                start = (start + 1) % gas.size();
                moves++;
                if (start >= current) current = start;
                //cout << "current gas: " << g << " not enough gas moved start to: " << start << " current position: " << current << endl;
            }
            g += gas[current] - cost[current];
            //cout << "current gas: " << g << " current position: " << current << " started at: " << start << endl;
            current = (current + 1) % gas.size();
        } while (start != current && moves < gas.size());

        if (current == start && g >= 0) return start;
        else return -1;
    }
};

int main() {
    Solution s;

    vector<int> gas = {1,2,3,3};
    vector<int> cost = {2,1,5,1};

    cout << s.canCompleteCircuit(gas, cost) << endl;

    vector<int> gas2 = {6,0,1,3,2};
    vector<int> cost2 = {4,5,2,5,5};

    cout << s.canCompleteCircuit(gas2, cost2) << endl;
}

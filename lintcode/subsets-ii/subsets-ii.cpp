class Solution {
    vector<vector<int> > generateSubsets(vector<int> &S, int start, vector<int> previous) {
        vector<vector<int> > results;

        if (previous.size() == S.size()) return results;

        for (int i=start; i<S.size(); i++) {
            if (i != start && S[i] == S[i-1]) continue;

            previous.push_back(S[i]);

            results.push_back(previous);

            vector<vector<int> > children = generateSubsets(S, i+1, previous);
            for (auto &child : children) {
                results.push_back(child);
            }

            previous.pop_back();
        }

        return results;
    }

public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> S) {
        sort(S.begin(), S.end());
        vector<vector<int> > subsets = generateSubsets(S, 0, vector<int>());
        subsets.push_back(vector<int>());

        return subsets;
    }
};

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(const vector<int> &S) {
        vector<vector<int> > subsets;
        long long counter = 0;
        double limit = pow(2.0, S.size());

        for (; counter < limit; counter ++) {
            vector<int> candidate;
            for (int i=0; i<S.size(); i++) {
                if (counter & (1 << i)) candidate.push_back(S[i]);
            }

            subsets.push_back(candidate);
        }

        return subsets;
    }
};

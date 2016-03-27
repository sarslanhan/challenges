class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        if (k == 0) return result;

        result.push_back(vector<int>()); // seed
        for (int i=0; i<k; i++) {
            vector<vector<int>> temp;

            for (int j=1; j <= n; j++) {
                for (auto &list : result) {
                    if (list.empty() || list.back() < j) {
                        vector<int> partial(list.begin(), list.end());
                        partial.push_back(j);
                        temp.push_back(partial);
                    }
                }
            }

            result.swap(temp);
        }

        return result;
    }
};

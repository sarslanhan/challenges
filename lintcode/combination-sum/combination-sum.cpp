class Solution {
    void combinationSum(vector<int> &candidates, int target, vector<int> &combination, vector<vector<int>> &result, int idx) {
        if (target < 0) return;
        else if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i=idx; i<candidates.size(); i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], combination, result, i);
            combination.pop_back();
        }
    }
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;

        combinationSum(candidates, target, combination, result, 0);

        return result;
    }
};

#define MIN(a,b) (a < b ? a : b)

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {

        if (strs.size() == 0) return "";
        else if (strs.size() == 1) return strs[0];

        int max_length = strs[0].size();
        for (auto &str : strs) {
            max_length = MIN(max_length, str.size());
        }

        int common_prefix_length = 0;
        for (int i=0; i<max_length; i++) {
            bool mismatch = false;
            char c = strs[0][i];

            for(int j=1; j<strs.size(); j++) {
                if (c != strs[j][i]) {
                    mismatch = true;
                    break;
                }
            }

            if (mismatch) {
                break;
            }

            common_prefix_length = i+1;
        }

        return strs[0].substr(0, common_prefix_length);
    }
};

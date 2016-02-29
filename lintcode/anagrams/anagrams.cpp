class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > collection;
        vector<string> result;

        for (auto &str : strs) {
            string copy(str);

            sort(copy.begin(), copy.end());

            auto it = collection.find(copy);

            if (it == collection.end()) {
                vector<string> l = { str };
                collection[copy] = l;
            } else {
                (*it).second.push_back(str);
            }
        }

        for (auto &pair : collection) {
            if (pair.second.size() > 1) {
                result.insert(result.begin(), pair.second.begin(), pair.second.end());
            }
        }

        return result;
    }
};

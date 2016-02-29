class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s.compare(t) == 0;
    }
};

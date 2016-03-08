class Solution {
    bool static cmp (int i,int j) {
        string i_str = to_string(i);
        string j_str = to_string(j);

        return i_str + j_str > j_str + i_str;
    }
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        stringstream ss;

        sort(num.begin(), num.end(), Solution::cmp);

        int zeroes = 0;
        for (int i=0; i<num.size(); i++) {
            if (num[i] == 0) {
                zeroes++;
                continue;
            }

            break;
        }

        for (int i=zeroes; i<num.size(); i++) {
            ss << num[i];
        }

        if (zeroes == num.size()) ss << 0;

        return ss.str();
    }
};

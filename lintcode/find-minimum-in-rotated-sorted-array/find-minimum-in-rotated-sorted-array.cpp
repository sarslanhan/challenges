class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        if (num.size() == 1) return num[0];

        if (num[0] < num[num.size()-1]) return num[0];

        int left = 0;
        int right = num.size()/2;
        while (left < right) {
            int old = right;

            //cout << left << " " << right << endl;

            if (num[left] <= num[right]) {
                left = right;
                right = right + (num.size() - right)/2;
            } else if (num[left] > num[right] && num[left] < num[left-1]) {
                break;
            } else {
                right = right - (right-left)/2;
            }

            //cout << "- " << left << " " << right << endl;

            if (old == right) break;
        }

        return num[right];
    }
};

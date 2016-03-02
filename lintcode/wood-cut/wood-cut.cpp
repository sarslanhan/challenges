class Solution {
    int count (vector<int> &L, int length) {
        int c = 0;

        if (length == 0) return c;

        for (auto &i : L) {
            c += i / length;
        }

        return c;
    }

    int max (vector<int> &L) {
        if (L.size() == 0) return 0;
        int max = L[0];

        for (auto &i : L) {
            if (max < i) max = i;
        }

        return max;
    }
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut (vector<int> L, int k) {
        int start = 0;
        int end = this->max(L);
        int length = start;

        while (start < end) {
            int old = length;
            length = start + (end - start) / 2;

            if (old == length) break;

            int _count = this->count(L, length);

            if (_count >= k) {
                start = length;
            } else {
                end = length;
            }
        }

        return length;
    }
};

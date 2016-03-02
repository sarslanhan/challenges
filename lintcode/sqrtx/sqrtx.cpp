class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {

        int start = 1;
        int end = x;

        do {
            long long mid = start + (end-start)/2;

            long long square = mid*mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                long long next = (mid+1)*(mid+1);

                if (next > x) return mid;

                start = mid;
            } else {
                end = mid;
            }

        } while (start < end);
    }
};

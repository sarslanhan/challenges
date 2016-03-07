class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int diff = 0;

        unsigned int x = a ^ b;

        while (x != 0) {
            int bit = x & 1;

            if (bit) diff++;

            x = x >> 1;
        }

        return diff;
    }
};

//14 = 01110
//31 = 11111

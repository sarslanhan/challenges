/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int start = 1;
        int end = n;

        int mid = end;

        while (start < end) {
            int old = mid;

            mid = start + (end - start) / 2;

            if (SVNRepo::isBadVersion(mid)) {
                if (!SVNRepo::isBadVersion(mid-1)) return mid;

                end = mid;
            } else {
                start = mid;
            }

            if (mid == old) break;
        }

        return SVNRepo::isBadVersion(mid) ? mid : mid+1;
    }
};

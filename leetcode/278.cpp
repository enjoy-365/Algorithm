// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int lo = 1;
        unsigned int hi = n;
        unsigned int mid = 1;

        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (!isBadVersion(mid)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return hi;
    }
};
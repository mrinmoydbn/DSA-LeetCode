// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid) == true) {
                high = mid; //Because earlier number including mid can be bad
            }
            else if (isBadVersion(mid) == false) {
                low = mid + 1; //If mid is not bad then we can search the the right half except mid
            }
        }
        return high;
    }
};
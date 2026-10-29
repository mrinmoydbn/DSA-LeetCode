class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        // Continue until only one candidate position remains.
        while(low < high) {
            int mid = low + (high - low) / 2;
            // Case 1: Minimum is in the right half.
            // nums[mid] is greater than nums[high],
            // so discard mid and everything to its left.
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Case 2: Minimum is at mid or in the left half.
            // Keep mid because it could itself be the minimum.
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
            // Case 3: Duplicates make the correct half ambiguous.
            // Since nums[mid] == nums[high], safely discard
            // one copy from the right by decrementing high.
            else {
                high--;
            }
        }
        // low == high: only one candidate remains.
        // That element is the minimum.
        return nums[low];
    }
};
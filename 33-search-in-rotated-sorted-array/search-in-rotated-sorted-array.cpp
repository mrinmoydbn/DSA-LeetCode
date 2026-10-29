class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            //Search which half is sorted
            else if (nums[low] <= nums[mid]) { //Check if left half is sorted
                if (nums[low] <= target && target < nums[mid]) {
                    //Search left search half
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else { //If left half is not sorted then right half is definitely sorted
                if (nums[mid] < target && target <= nums[high]) { //Check if right half is sorted
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
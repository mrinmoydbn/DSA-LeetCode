class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
            else { //If nums[mid] == nums[high] then we know mid and high are duplicate do we can safely remove high 
                high--;
            }
        }
        return nums[low];
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int count = 0;
        int sum = 0;
        vector<int> ans;

        for (int num : nums) {
            sum += num;
            int needed = sum - k;
            if (mp.find(needed) != mp.end()) {
                count += mp[needed];
            }
            mp[sum]++;
        }
        return count;
    }
};
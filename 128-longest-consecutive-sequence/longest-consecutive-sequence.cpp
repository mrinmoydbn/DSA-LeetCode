class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;
        for (int num : nums) {
            seq.insert(num);
        }
        int beststart = 0;
        int bestlength = 0;
        for (int num : seq) {
            if (seq.find(num - 1) == seq.end()) {
                int current = num;
                int length = 1;
                while (seq.find(current + 1) != seq.end()) {
                    current++;
                    length++;                   
                }
                if (length > bestlength) {
                        bestlength = length;
                        beststart = num;
                }
            }
        }
        return bestlength;
    }
};
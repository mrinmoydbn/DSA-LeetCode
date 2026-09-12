class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        if (s1.size() > s2.size()) {
            return false;
        }
        //Frequency of s1 characters
        for (int i = 0; i < s1.size(); i++) { 
            freq1[s1[i] - 'a']++;
        }
        //First sliding window
        for (int i = 0; i < s1.size(); i++) {
            freq2[s2[i] - 'a']++;
        }
        if (matches(freq1, freq2)) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            //Character entering
            freq2[s2[i] - 'a']++;
            //Character leaving
            freq2[s2[i - s1.size()] - 'a']--;
            if (matches(freq1, freq2)) {
                return true;
            }
        }
        return false;
    }

    bool matches(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
};
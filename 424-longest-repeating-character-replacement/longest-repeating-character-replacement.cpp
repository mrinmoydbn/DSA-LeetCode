class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int freq[26] = {0};
        int maxfreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            //Frequency counting of characters
            freq[s[right] - 'A']++;
            //Checking max frequency character
            maxfreq = max(maxfreq, freq[s[right] - 'A']);
            //Checking is window is valid
            while ((right - left + 1) - maxfreq > k) { // Window size => right - left + 1
                //If window is invalid then enter this loop
                //Shrinking the window from left
                freq[s[left] - 'A']--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
            
        }
        return ans;
    }
};
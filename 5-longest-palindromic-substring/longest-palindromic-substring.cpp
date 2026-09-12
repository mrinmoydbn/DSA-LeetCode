class Solution {
public:

    int expand(string &s, int left, int right) {

        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int end = 0;
      

        for (int i = 0; i < s.size(); i++) {

            int oddlen = expand(s, i, i);
            int evenlen = expand(s, i, i + 1);

            int maxlen = max(oddlen, evenlen);

            if (maxlen > end - start + 1) {
                start = i - (maxlen - 1) / 2;
                end = i + maxlen / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
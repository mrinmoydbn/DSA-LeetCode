class Solution {
public:

    int expand(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int countlen = 0;

        for (int i = 0; i < s.size(); i++) {
            int oddlen = expand(s, i, i);
            countlen += oddlen;
            int evenlen = expand(s, i, i + 1); 
            countlen += evenlen;   
        }
        return countlen;        
    }
};
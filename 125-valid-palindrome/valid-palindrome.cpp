class Solution {
public:

    bool checkpalindrome(string& s, int left, int right) {
        if (left >= right) {
            return true;
        }
        if (!isalnum(s[left])) {
            return checkpalindrome(s, left + 1, right);
        }
        if (!isalnum(s[right])) {
            return checkpalindrome(s, left, right - 1);
        }
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        return checkpalindrome(s, left + 1, right - 1);
    }

    bool isPalindrome(string s) {
        return checkpalindrome(s, 0, s.size() - 1);
    }
};
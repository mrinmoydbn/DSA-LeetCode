class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        
        int i = 0;
        int j = 0;
        while (i < n || j < m) {
            int num1 = 0;
            int num2 = 0; 
            while (i < n && version1[i] != '.') {
                int digit = version1[i] - '0';
                num1 = num1 * 10 + digit;
                i++;
            }
            while (j < m && version2[j] != '.') {
                int digit = version2[j] - '0';
                num2 = num2 * 10 + digit;
                j++;
            }
            if (num1 < num2) {
                return -1;
            }
            if (num1 > num2) {
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};
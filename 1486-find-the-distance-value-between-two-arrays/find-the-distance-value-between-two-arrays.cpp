class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                int absDiff = abs(arr1[i] - arr2[j]);
                if (abs(absDiff) <= d) {
                    flag = false;                   
                }
            }
            if (flag == true) {
                count++;
            }
        }
        return count;
    }
};
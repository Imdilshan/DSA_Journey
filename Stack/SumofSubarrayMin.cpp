// Brute force Approach
// Will produce TLE
class Solution {
public:
    // brute force generating all subarrays O(n^2)
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9 + 7;
        long long sum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int ans = arr[i];
            for(int j = i; j < n; j++){
                ans = min(ans, arr[j]);
                sum = (sum + ans) % mod;
            }
        }
        return sum;
    }
};

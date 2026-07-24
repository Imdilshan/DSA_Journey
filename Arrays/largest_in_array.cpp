// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
class Solution {
  public:
    int largest(vector<int> &arr) {
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            ans = max(ans, arr[i]);
        }

        return ans;
    }
};

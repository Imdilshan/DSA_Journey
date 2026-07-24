// https://www.geeksforgeeks.org/problems/second-largest3735/1
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int mx = arr[0], sec_mx = -1;
        for(int i = 0; i < arr.size(); i++){
            if(mx < arr[i]){
              sec_mx = mx;
              mx = arr[i];
            }
            else if(sec_mx < arr[i] && arr[i] != mx){
                sec_mx = arr[i];
            }
        }

        return sec_mx;

    }
};

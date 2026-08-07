// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1

class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        vector<int> ans;

        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                int curr = arr1[i];
                while(arr1[i] == curr) i++;
                while(arr2[j] == curr) j++;
            }
            else if(arr1[i] < arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};

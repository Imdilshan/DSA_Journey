//https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        vector<int> v;
        int i = 0, j = 0;
        while(i < n && j < m){
            int curr;
            if(a[i] <= b[j]){
                curr = a[i];
                v.push_back(a[i]);
                i++;
            }
            else{
                curr = b[j];
                v.push_back(b[j]);
                j++;
            }
            while(a[i] == curr) i++;
            while(b[j] == curr) j++;
        }

        while(i < n){
            int curr = a[i];
            v.push_back(a[i]);
            i++;
            while(a[i] == curr) i++;
        }
        while(j < m){
            int curr = b[j];
            v.push_back(b[j]);
            j++;
            while(b[j] == curr) j++;
        }

        return v;
    }
};

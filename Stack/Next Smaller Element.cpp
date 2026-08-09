// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            int curr = arr[i];
            while(!st.empty() && curr <= st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(curr);
        }
        return ans;
    }
};

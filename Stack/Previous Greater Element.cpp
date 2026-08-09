// https://www.geeksforgeeks.org/problems/previous-greater-element/1

class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++){
            int curr = arr[i];

            while(!st.empty() && curr >= st.top()){
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

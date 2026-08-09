// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Think of light poles in increasing order when thinking about next greater element

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);

        stack<int> st;

        for(int i = n-1; i >= 0; i--){
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

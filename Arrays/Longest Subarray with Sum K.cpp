// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int mxlen = 0;
        long long sum = 0;
        map<long long, int> mp;

        for(int i = 0; i < n; i++){
            sum += arr[i];

            if(sum == k){
                mxlen = max(mxlen, i+1);
            }

            long long rem = sum - k;
            if(mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                mxlen = max(mxlen, len);
            }

            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }

        return mxlen;
    }
};



--------------------------------------

    class Solution {
    public:
        int longestSubarray(vector<int>& arr, int k) {
            long long sum = 0;
            int mxlen = 0;

            map<long long, int> mp;
            mp[0] = -1;

            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];

                long long rem = sum - k;

                if (mp.find(rem) != mp.end()) {
                    mxlen = max(mxlen, i - mp[rem]);
                }

                if (mp.find(sum) == mp.end()) {
                    mp[sum] = i;
                }
            }

            return mxlen;
        }
    };

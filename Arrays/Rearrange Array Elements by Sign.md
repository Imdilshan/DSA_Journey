Link: []

## Brute Force
- Make 2 array pos and neg, push elements into them, then push to final array.
- TC: O(n)
- SC: O(n)

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        vector<int> ans;
        for(int i = 0; i < pos.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};
```

## Optimal
- fix positive at even index, negative at odd index
- TC: O(n)
- SC: O(n)

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};
```

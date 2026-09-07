Link: [https://www.codechef.com/practice/course/arrays-strings-advanced/ARRAYSP06/problems/PRINTSUBARAY]

## Optimal
- Printing the maximum sum subarray, if tie:
  - choose longest
  - choose leftmost
- TC: O(n)
- SC: O(n)

```cpp
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = INT_MIN;
        int sum = 0;
        
        int starti = 0;
        int endi = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += nums[i];
            
            int baselength = endi -starti +1;
            int currentlength = i -start +1;
            
            if(sum > maxi || (maxi == sum && currentlength > baselength)){
                maxi = sum;
                starti = start;
                endi = i;
            }
            
            if(sum < 0){
                sum = 0;
                start = i + 1;
            }
        }
        
        vector<int> ans;
        for(int i = starti; i <= endi; i++){
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};
```


Link: [https://www.geeksforgeeks.org/problems/maximum-sub-array5443/1]

## Optimal
- Printing the maximum sum subarray, if tie:
  - choose longest
  - choose leftmost
- if only negative numbers are present return -1;
- TC: O(n)
- SC: O(n)

```cpp
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int maxi = INT_MIN;
        int sum = 0;
        
        int start = 0;
        int starti = 0;
        int endi = 0;
        
        for(int i = 0; i < n; i++){
            
            if(arr[i] < 0){
                sum = 0;
                start = i+1;
                continue;
            }
            
            sum += arr[i];
            
            int currlen = i - start + 1;
            int baselen = endi - starti + 1;
            
            if(sum > maxi || (sum == maxi && currlen > baselen)){
                maxi = sum;
                starti = start;
                endi = i;
            }
            
            
        }
        
        if(maxi < 0) return {-1};
        
        vector<int> ans;
        for(int i = starti; i <= endi; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
```

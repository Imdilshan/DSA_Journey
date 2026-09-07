Link: []

## Brute Force
- Generate all subarrays, keep the sum, compare to maxi, return maxi
- TC: O(n^3)
- SC: 1

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum += nums[k];
                }
                 maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
```

## Better Approach
- In subarray generation the next array is just adding the next element in previous subarray
- TC: O(n^ 2)
- SC: O(1)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[j];
            maxi = max(maxi, sum);

            if(sum < 0) sum = 0;
        }

        return maxi;
    }
};
```

## Optimal
- maintain two variables sum and maxi, make maxi as min as possible
- in each iteration take the make of maxi and sum, and update maxi
- if at any point sum become negative, abort it. (Don't carry negatives in future!!)
- if sum is positive keep it, even if it contains negative elements (kabhi kabhi kuch nuksaan bhi long term me benefetial hote hai)
- TC:
- SC:

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxi = max(maxi, sum);

            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
```

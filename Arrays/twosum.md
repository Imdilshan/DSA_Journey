Link: [https://leetcode.com/problems/two-sum/description/]

## Brute Force
- Find the required value by subtracting the current value from target => Val = target - arr[i]
- TC: O(n^2)
- SC: O(1)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int val = target - nums[i];
            for(int j = i+1; j < n; j++){
                if(nums[j] == val){
                    return {i, j};
                }
            }
        }

        return {0,0};
    }
};
```


## Better
- use a hashmap for searching whether value is present in array or not.
- TC: O(n log n)
- SC: O(n)
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int val = target - nums[i];

            if(mp.count(val)){
                return {i, mp[val]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
```

## Optimal
- Using map structure is not allowed, then use sorting + 2 pointers
- TC and SC will be same as better approach
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums1 = nums;
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        int ind1 = -1, ind2 = -1, val1, val2;

        while(l < r){
            if(nums[l] + nums[r] == target){
                val1 = nums[l];
                val2 = nums[r];
                break;
            }
            else if(nums[l] + nums[r] < target){
                l++;
            }
            else{
                r--;
            }
        }

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] == val1 && ind1 == -1){
                ind1 = i;
            }

            if(nums1[i] == val2 && i != ind1){
                ind2 = i;
            }
        }

        return {ind1, ind2};
    }
};
```

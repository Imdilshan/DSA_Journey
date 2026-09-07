Link: [https://leetcode.com/problems/sort-colors/description/]

## Brute Force
- Just use any sorting algo which uses in-place sorting

## Better Approach
- Just count the occurances of each digit and put them in the array
- Tc: O(n)
- Sc: O(1)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0, two = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] == 1) one++;
            else two++;
        }

        for(int i = 0; i < zero; i++){
            nums[i] = 0;
        }
        for(int i = zero; i < zero+one; i++){
            nums[i] = 1;
        }
        for(int i = zero+one; i < zero+one+two; i++){
            nums[i] = 2;
        }
    }
};

```

## Optimal
- If i am not allowed to do counting or 2 iterations, i have to do in just 1 iterations.
- TC: O(n)
- SC: O(1)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```

Link: [https://leetcode.com/problems/majority-element/description/]

## Brute Force
- Pick an element scan it in the entire array if the frequency > n/2 , return it.
- TC: O(n^2)
- SC: 1

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt > (n/2)){
                return nums[i];
            }
        }
        return 0;
    }
};
```

## Better Approach
- Use a map for counting frequency of each element, then return the element with max frequency
- TC: O(n log n)
- SC: O(n)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        
        for(auto &x: mpp){
            if(x.second > (n/2) ) return x.first;
        }
 
        return 0;
    }
};
```

## Optimal
- cross the frequency of current element with another elem, when frequency reaches zero pick the next elem as candidate and repear
- the highest frequent element will become our elem as last
- the highest frequent element doesnot stay consistent in entire array, it may get swapped in between.
- May loose in short term, but will win in long term (bade samandar se jitne se pehle, choti nadiyon se haarna pdta hai,,)
- TC: O(n)
- SC: O(1)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, elem = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                elem = nums[i];
                cnt++;
            }
            else if(nums[i] == elem){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == elem) cnt++;
        }

        if(cnt > (n/2)){
            return elem;
        }
        return -1;
    }
};
```

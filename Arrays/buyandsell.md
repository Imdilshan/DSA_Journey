Link: []

## Brute Force
- Generate all possible scenarios and pick the best one
- TC: O(n^2)
- SC: O(1)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxi = 0;
        int n = prices.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                maxi = max(maxi, prices[j] - prices[i]);
            }
        }
        
        return maxi;
    }
};
```

## Optimal
- Initialize two variables:
  - 1. min: to find the stock with minimum price so far
  - 2. profit: to find the profit after selling the stock at current price compared to buying at minimum price stock
- TC: O(n)
- SC: O(1)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }

            int profit = prices[i] - mini;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
```

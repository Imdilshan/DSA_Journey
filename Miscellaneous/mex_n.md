Link: [https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c]

## Solution
- The answer is monotonic so it will only increase and never decrease.
- TC: O(NlogN)
- SC: O(N)

```cpp
void solve(){
  int n;
  cin >> n;
  
  vector<int> arr(210001, 0);
  int ans = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    
    arr[x]++;
    while(arr[ans]){
      ans++;
    }
    cout << ans << endl;
  }
}
```

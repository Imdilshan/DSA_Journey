# Number of Good Pairs

## Problem
You are given two arrays `arr1` and `arr2`, each of size `n`.

A pair of indices `(i, j)` is called **good** if all of the following hold:

1. `i < j`
2. `arr1[i] == arr2[j]`
3. `arr1[j] == arr2[i]`

Find the number of good pairs.

## Input
- The first line contains an integer `T`, the number of test cases.
- For each test case:
  - The first line contains an integer `n`.
  - The second line contains `n` integers, the elements of `arr1`.
  - The third line contains `n` integers, the elements of `arr2`.

## Output
For each test case, print a single integer: the number of good pairs.

## Constraints
- 1 ≤ T ≤ 1000
- 1 ≤ i < j ≤ n
- 1 ≤ n ≤ 100000
- Sum of `n` over all test cases ≤ 100000

## Example

### Input
```
2
4
1 2 3 2
2 1 4 1
3
4 8 11
8 4 11
```

### Output
```
2
1
```

### Explanation
Test 1: viewing each index as the pair `(arr1[k], arr2[k])` gives `(1,2), (2,1), (3,4), (2,1)`. Indices `(0,1)` and `(0,3)` are good, so the answer is 2.

Test 2: the pairs are `(4,8), (8,4), (11,11)`. Only indices `(0,1)` are good, so the answer is 1.

## Approach
Treat each index `k` as the pair `(arr1[k], arr2[k])`. Indices `i` and `j` form a good pair exactly when one pair is the reverse of the other. Scan left to right keeping a map from pair to count. For each index, add the count of its reverse pair to the answer, then insert the current pair.

## Complexity
- Time: O(n log n) with an ordered map
- Space: O(n)


---

Solution:
/* Author -> highfive */
#include <bits/stdc++.h>
using namespace std;

/* To Make I/O faster */
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

/* Macro */
#define int long long
#define ld long double
#define pb push_back
#define endl '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

/* Containers */
typedef pair<int,int> pi;
typedef map<int,int> mpi;
typedef priority_queue<int> mxpq;
typedef priority_queue<int, vector<int>, greater<int>> mnpq;

const int N = 1e5;

void solve(){
  int n;
  cin >> n;
  
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }
  map<pair<int,int>,int> mp;
  int ans = 0;
  for(int i = 0; i < n; i++){
      auto it = mp.find({b[i], a[i]});
      if(it != mp.end()){
          ans += it->second;
      }
      mp[{a[i], b[i]}]++;
  }
  cout << ans << endl;
}

signed main(){
  fastio;
  int tc;
  cin >> tc;
  
  while(tc--){
      solve();
  }
  return 0;
}

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
  string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;
  cin >> s1 >> s2 >> s3 >> s4 >> s5;
  
s6 = {s1[0], s2[0], s3[0], s4[0], s5[0]};

s7 = {s1[1], s2[1], s3[1], s4[1], s5[1]};

s8 = {s1[2], s2[2], s3[2], s4[2], s5[2]};

s9 = {s1[3], s2[3], s3[3], s4[3], s5[3]};

s10 = {s1[4], s2[4], s3[4], s4[4], s5[4]};

s11 = {s1[0], s2[1], s3[2], s4[3], s5[4]};

s12 = {s1[4], s2[3], s3[2], s4[1], s5[0]};
  
  int ans = 5, cnt = 0;
  for(int i = 0; i < 5; i++){
    if(s1[i] == '.') cnt++;
  }
  ans = min(ans, cnt);
  cnt = 0;
  for(int i = 0; i < 5; i++){
    if(s2[i] == '.') cnt++;
  }
  ans = min(ans, cnt);
  cnt = 0;
  for(int i = 0; i < 5; i++){
    if(s3[i] == '.') cnt++;
  }
    ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s4[i] == '.') cnt++;
  }
    ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s5[i] == '.') cnt++;
  }
    ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s6[i] == '.') cnt++;
  }
  ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s7[i] == '.') cnt++; 
  }
    ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s8[i] == '.') cnt++;
  }
    ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s9[i] == '.') cnt++;
  }
  ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s10[i] == '.') cnt++;
  }
    ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s11[i] == '.') cnt++;
  }
    ans = min(ans, cnt);
  cnt = 0;
  
  for(int i = 0; i < 5; i++){
    if(s12[i] == '.') cnt++;
  }
    ans = min(ans, cnt);
  cnt = 0;
  cout << ans << endl;
}

signed main(){
  fastio;
  // int tc;
  // cin >> tc;
  
  // while(tc--){
  //   solve();
  // }
  solve();
  return 0;
}

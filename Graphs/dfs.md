/*
 * Store starting node, Create an visited array & traversal array
 * call the dfs function
 * create a dfs function with parameters starting node, adj list, visited array, traversal array
 * pass them by reference to avoid multiple copies & TLE
 * mark each visited note at 1 and push node in traversal array
 * iterate each neighbours until the no neighbours exist, then backtrack.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &traversal){
        vis[node] = 1;
        traversal.push_back(node);

        // Visit neighbours
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, traversal);
            }
        }
    }

  public:
    vector<int> dfsGraph(vector<vector<int>>& adj) {
        int n = adj.size();

        int start = 0;
        vector<int> vis(n, 0);
        vector<int> traversal;

        dfs(start, adj, vis, traversal);
        return traversal;
    }
};

// Method 2

/* Author -> highfive */
#include <bits/stdc++.h>
using namespace std;

/* To Make I/O faster */
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

/* Macro */
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

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans){
  vis[node] = 1;
  ans.push_back(node);
  
  for(auto it: adj[node]){
    if(!vis[it]){
      dfs(it, adj, vis, ans);
    }
  }
}

void solve(){
  int n, m;
  cin >> n >> m;
  
  vector<int> adj[n+1];
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int start = 1;
  vector<int> vis(n+1, 0);
  vector<int> ans;
  dfs(start, adj, vis, ans);
  
  for(auto x: ans){
    cout << x << " ";
  } 
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

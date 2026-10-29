/*
 * Key idea of bfs:
 * - Create a visited array, initialize everthing with 0, make starting node 1
 * - Create a queue, push starting node in queue
 * - Create a vector, to store bfs traversal
 * - loop until the queue becomes empty, at each step:
 *  - store the node at front of queue, push that node in vector, pop that node off of queue
 *  - now visit every neighbour of that node in adj list
 *      - check if the node is unvisited, if yes then mark it as visited and add it in the queue.
 * - return the final vector that stores traversal.
 *
 * that's it bfs traversal will be completed.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();

        int vis[n] = {0};
        vis[0] = 1;

        queue<int> q;
        q.push(0);

        vector<int> bfs;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
    }
};


// Method 2
//
// /* Author -> highfive */
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
  int n, m;
  cin >> n >> m;

  vector<int> adj[n+1];
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> vis(n+1,0);
  queue<int> q;
  vector<int> bfs;

  int node;
  cin >> node;

  q.push(node);
  vis[node] = 1;

  while(!q.empty()){
    int val = q.front();
    q.pop();
    bfs.push_back(val);

    for(int x: adj[val]){
      if(!vis[x]){
        q.push(x);
        vis[x] = 1;
      }
    }
  }

  for(int i = 0; i < bfs.size(); i++){
    cout << bfs[i] << " ";
  }

  /*
    9 9
    1 2
    1 6
    2 3
    2 4
    4 5
    5 8
    6 7
    6 9
    7 8
  */
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

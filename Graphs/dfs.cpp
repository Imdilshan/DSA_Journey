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

/*
 * Convert adj matrix to list,
 * create and visited array, count variable for storing components
 * Each dfs call will visit all neighbours and its component in one call
 * so no. of dfs calls = no. of connected components.
 * return count
 *
 * this is the dfs version, will do it in bfs too.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }

    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && (i != j)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }
};

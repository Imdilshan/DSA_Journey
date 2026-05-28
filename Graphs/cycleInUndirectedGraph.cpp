/*
 * If you start traversal in an undirected graph and you reach a node which has already been visited
 * just check that is it the aprent from where you came from ?
 * if yes -> continue the traversal
 * if no -> cycle exists (some another path lead to that node)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool detect(int source, vector<int> &vis, vector<vector<int>> &adj){

        queue<pair<int,int>> q;
        q.push({source, -1});
        vis[source] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto x : adj[node]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push({x, node});

                }
                else if(x != parent){
                    return true;
                }
            }
        }
        return false;
    }

  public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for(auto x: edges){
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detect(i, vis, adj)) return true;
            }
        }
        return false;
    }
};

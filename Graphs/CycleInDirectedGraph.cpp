/* Create 2 arrays: 1) visited and 2) Path visited
 * run a dfs for each unvisited node, when performing dfs mark each visited node in vis array as 1
 * check whether any node apear in same path -> return true
 * If not check if array is already visited but now the path visited leads to a cycle.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool cycle(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto x : adj[node]){
            if(!vis[x]){
                if(cycle(x, vis, pathVis, adj)){
                    return true;
                }
            }
            else if(pathVis[x]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        vector<vector<int>> adj(n);
        for(auto x : prerequisites){
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(cycle(i, vis, pathVis, adj)){
                    return false;
                }
            }
        }

        return true;
    }
};

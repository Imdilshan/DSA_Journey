## Link: [https://www.geeksforgeeks.org/problems/number-of-provinces]

## Using DFS
- No. of dfs calls = number of provinces;
- TC: O(V+E)
- SC: O(V+E)

```cpp
class Solution {
private:
void dfs(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        
        return cnt;
    }
};
```

## Using bfs
- No. of bfs calls = no. of provinces
- TC: O(V+E)
- SC: O(V+E)

```cpp
class Solution {
private:
void bfs(int i, vector<int> adj[], vector<int> &vis, queue<int> &q){
    q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    
}
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                bfs(i, adj, vis, q);
            }
        }
        
        return cnt;
    }
};
```

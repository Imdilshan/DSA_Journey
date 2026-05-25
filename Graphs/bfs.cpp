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

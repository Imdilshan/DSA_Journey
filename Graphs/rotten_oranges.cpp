/*
 * Find all rotten oranges, push them in queue with their time = 0;
 * explore all rotten oranges one by one, if fresh orange -> rotten, update in visited grid, push in queue
 * Repeat for all rotten oranges
 * check if any fresh orange remains -> -1, else return max time.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int mxTime = 0;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;

            int time = q.front().second;
            mxTime = max(mxTime, time);
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, time + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }

        return mxTime;
    }
};

/*
 * Find shortest distance of land cell from a water cell.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({{i,j}, 0});
                }
            }
        }

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto it = q.front();
            int r = it.first.first;
            int c = it.first.second;
            int score = it.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc]== 0){
                    vis[nr][nc] = 1;
                    ans[nr][nc] = score + 1;
                    q.push({{nr, nc}, score+1});
                }
            }
        }
        return ans;
    }
};

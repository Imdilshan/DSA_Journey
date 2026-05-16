#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj_lst[n+1];
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj_lst[u].push_back({v, w});
        adj_lst[v].push_back({u, w});
    }

    for(int i = 0; i < n+1; i++){
        cout << i << ": ";
        for(int j = 0; j < adj_lst[i].size(); j++){
            cout << "(" << adj_lst[i][j].first << ", " << adj_lst[i][j].second << ") " ;
        }
        cout << endl;
    }

    return 0;
}

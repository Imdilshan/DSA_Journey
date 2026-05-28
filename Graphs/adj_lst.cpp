#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    // vector<int> adj_list[n+1];
    vector<vector<int>> adj_list(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    cout << "<-Final List->" << endl;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

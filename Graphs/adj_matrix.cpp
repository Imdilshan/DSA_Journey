#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int adj_mtrx[n+1][n+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            adj_mtrx[i][j] = 0;
        }
        cout << endl;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj_mtrx[u][v] = 1;
        adj_mtrx[v][u] = 1;
    }

    cout << "<-Final Matrix->" << endl;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            cout << adj_mtrx[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	
	if(x > y) cout << "Alice";
	else if(y > x) cout << "Bob";
	else cout << "Draw" << endl;

}

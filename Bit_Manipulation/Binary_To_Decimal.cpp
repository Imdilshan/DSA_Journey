#include <bits/stdc++.h>
using namespace std;

int binToDec(string s){
  int ans = 0;
  int size = s.size();
  for(int i = 0; i < size; i++){
    if(s[i] == '1'){
      ans += pow(2, (size-1-i));
    }
  }
  return ans;
}

int binToDecI(string s){
  int p2 = 1, num = 0, len = s.size()-1;
  for(int i = len; i >= 0; i--){
    if(s[i] == '1'){
      num += p2;
    }
    p2 = p2 * 2;
  }
  return num;
}

int main(){
  string s;
  cin >> s;
  cout << binToDec(s) << endl;
  cout << binToDecI(s) << endl;
  return 0;
}

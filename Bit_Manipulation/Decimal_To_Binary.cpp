#include <bits/stdc++.h>
using namespace std;

// Recursive Method
string decToBin(int number){
  if(number == 0) return "0";
  if(number == 1) return "1";
  
  string ans = "";
  int rem = number % 2;
  ans += to_string(rem);
  return decToBin(number / 2) + ans;  // ans will store the binary value to be added during backtracking
}

// Iterative Method
string decToBin_Iter(int number){
  if(number == 0) return "0";
  string ans = "";
  while(number >= 1){
    ans += to_string(number % 2);
    number /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  int n;
  cout << "Enter Number: ";
  cin >> n;
  
  cout << "The Binary form: " << decToBin(n) << endl;
  cout << "The Binary form: " << decToBin_Iter(n) << endl;
  return 0;
}

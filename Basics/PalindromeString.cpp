/*
 * check if the String is same if we read it from left and right => racecar
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(),s.end(),s.begin(),::tolower);
        string a;
        for(int i = 0; i < s.size(); i++){
            if( (48 <=s[i] && s[i] <= 57) || (65 <=s[i] && s[i] <= 90) || (97 <=s[i] && s[i] <= 122) ){
                a += s[i];
            }
        }
        bool flag = true;
  	    int l = 0, r = a.size()-1;
  	    while(l <= r){
            if(a[l] != a[r]){
  			    flag = false;
  			    break;
  		    }
            else{
    	  		l++;
    	  		r--;
            }
      	}
       	if(flag) return 1;
       	else return 0;
    }
};

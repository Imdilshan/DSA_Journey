/*
 * check if the String is same if we read it from left and right => RacecaR
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool  isPalindrome(long long int num){
        if(num < 0) return false;
        long long int rev = 0;
        long long int original = num;
    while(num != 0){
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }
        return original == rev;
    }
};

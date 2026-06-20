
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto &x: strs){
            s += to_string(x.size()) + "#" + x;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int start = 0;
        while(start < s.size()){
            int curr_pos = start;

            while(s[curr_pos] != '#') curr_pos++;

            int len = stoi(s.substr(start, curr_pos - start));
            ans.push_back(s.substr(curr_pos + 1, len));

            start = curr_pos + 1 + len;
        }

        return ans;

    }
};

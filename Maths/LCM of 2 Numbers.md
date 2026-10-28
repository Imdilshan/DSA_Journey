class Solution {
public:
    int GCD(int a, int b){
        if(a == 0){
            return b;
        }
        return GCD(b%a, a);
    }
    int LCM(int n1,int n2) {
        return (n1 * n2) / GCD(n1, n2);
    }
};

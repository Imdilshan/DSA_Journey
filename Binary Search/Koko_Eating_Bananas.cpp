class Solution {
public:
    bool canEat(vector<int> piles, int rate, int h){
        long long total = 0;
        for(int i = 0; i < piles.size(); i++){
            total += (piles[i] +rate -1) / rate;
        }
        if(total <= h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            bool can = canEat(piles, mid, h);

            if(can == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};

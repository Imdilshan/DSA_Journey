class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l+1 < r){
            int mid = l + (r-l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid;
            else r = mid;
        }
        if(nums[l] == target) return l;
        return -1;
    }
};

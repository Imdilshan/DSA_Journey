class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int l = 0, r = nums.size()-1;
        int p1 = -1, p2 = -1;

        while(l <= r){
            int mid = l + (r-l) / 2;

            if(nums[mid] == target){
                p2 = mid;
                l = mid + 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r-l) / 2;

            if(nums[mid] == target){
                p1 = mid;
                r = mid - 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return {p1, p2};    
    }
};

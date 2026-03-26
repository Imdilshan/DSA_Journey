/*
one problem that might occur here due to repetition of elements that you may encounter ambiguity: when left, mid, and right are same
and binary search eliminates the wrong half.
When this condition arised shift the pointers by 1, left++, right--.

Case: Array: [1,0,1,1,1]  Target: 0

The core idea:
Rotated sorted array is array where one half will be sorted and another half will be unsorted, this idea break in the duplicate element case
when left == mid and mid == right. so to remove the chance of eliminating wrong half we shift the pointers by one (l++, r--).
until we have got the sorted and unsorted half.
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r-l) / 2;
            if(nums[mid] == target){
                return true;
            }

            if(nums[l] == nums[mid] && nums[mid] == nums[r]){  // Heart of the code
                l++;
                r--;
            }
              
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

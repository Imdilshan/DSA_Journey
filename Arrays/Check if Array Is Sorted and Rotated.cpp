// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

/*
 * There are 2 properties of an sorted and rotated array:
 * 1) One half will always be sorted and other half will be unsorted
 * 2) There will always <= 1 inversion (arr[i] > arr[i+1]), 0 for rotation at index 0.
*/

class Solution {
public:
    bool check(vector<int>& nums) {

        int inversion = 0, n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                inversion++;
            }
        }
        if(nums[n-1] > nums[0]){
            inversion++;
        }

        if(inversion <= 1) return true;
        return false;
    }
};

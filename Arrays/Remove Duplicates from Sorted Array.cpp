// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/2081770828/

/*
 * Used 2 pointers approach
 *  - Used mainly for iterating a data structure more efficiently than nested loops.
 *  - Reduces Time Complexity from O(n^2) to O(n).
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 1; j < n; j++){
            if(nums[i] == nums[j]){
                continue;
            }
            else{
                nums[i+1] = nums[j];
                i = i + 1;
            }
        }

        return i+1;
    }
};

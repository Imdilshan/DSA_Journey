// https://leetcode.com/problems/rotate-array/description/

/*
 * To rotate array in place by k digits:
 * - Think what rotation actually means ans how we can achieve it
 * - 2 Types -> Left Rotation, Right Rotation
*/

class Solution {
public:
    void reverseArray(vector<int> &nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }

    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1) return;
        int n = nums.size();
        k = k % n;

        reverseArray(nums, 0, n-1);
        reverseArray(nums, 0, k-1);
        reverseArray(nums, k, n-1);
    }
};

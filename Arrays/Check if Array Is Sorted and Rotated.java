class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int inversion = 0;

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                inversion++;
            }
        }
        if(nums[n-1] > nums[0]) inversion++;

        if(inversion <= 1) return true;
        return false;

    }
}

// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
// Java uses Math class for functions like: max, min, sqrt etc...
// Eg: Math.max(a, b)


class Solution {
    public static int largest(int[] arr) {
        int ans = arr[0];

        for(int i = 0; i < arr.length; i++){
            ans = Math.max(ans, arr[i]);
        }
        return ans;
    }
}

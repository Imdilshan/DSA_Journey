// https://www.geeksforgeeks.org/problems/second-largest3735/1
class Solution {
    public int getSecondLargest(int[] arr) {
        int mx = -1, sec_mx = -1;
        for(int i = 0; i < arr.length; i++){
            if(mx < arr[i]){
                sec_mx = mx;
                mx = arr[i];
            }
            else if(arr[i] > sec_mx && arr[i] != mx){
                sec_mx = arr[i];
            }
        }

        return sec_mx;

    }
}

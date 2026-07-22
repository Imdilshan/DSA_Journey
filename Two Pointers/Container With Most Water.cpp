class Solution {
public:
    int maxArea(vector<int>& h) {
        int area = 0;
        int left = 0, right = h.size() - 1;

        while(left < right){
            area = max(area, min(h[left], h[right]) * (right - left));

            if(h[left] < h[right]) left++;
            else right--;
        }

        return area;
    }
};

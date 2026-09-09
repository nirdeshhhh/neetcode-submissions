class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0;
        int j = n-1;
        int mx = -1;

        while(i < j){
            int warea = (j-i) * min(heights[i], heights[j]);
            if(heights[i]<heights[j]) i++;
            else j--;
            mx = max(mx, warea);
        }
        return mx;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; 
        int j=height.size()-1;
        int area=0;
        int maxarea=0; 
        while(i<j){
            int h=min(height[i], height[j]);
            int b=j-i;
            area=h*b;
            maxarea=max(area, maxarea);
            // Move the pointer having smaller height
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};
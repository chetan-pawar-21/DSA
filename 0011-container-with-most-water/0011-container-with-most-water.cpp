class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j=height.size()-1;
        int area = 0;
        
        while(i<j){
            int length = min(height[i], height[j]);
            int width = j-i;

            area = max(area, length*width);

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return area;
    }
};
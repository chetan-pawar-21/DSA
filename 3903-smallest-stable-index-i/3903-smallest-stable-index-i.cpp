class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        vector<int> minimum(nums.size(),0);

        for(int i=nums.size()-1; i>=0; i--){
            mini = min(mini, nums[i]);
            minimum[i] = mini;
        }

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            if (maxi - minimum[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
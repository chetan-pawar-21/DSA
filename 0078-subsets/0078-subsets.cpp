class Solution {
public:
    void findSubSet(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        if(index == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        findSubSet(index+1, nums, ans, ds);
        ds.pop_back();

        findSubSet(index+1, nums, ans, ds);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0;
        findSubSet(0, nums, ans, ds);

        return ans;
    }
};
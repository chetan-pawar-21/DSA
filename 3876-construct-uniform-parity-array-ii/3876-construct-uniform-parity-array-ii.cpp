class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini = 1e9;

        bool allEven = false;
        bool allOdd = false;
        for (auto& it : nums1) {
            mini = min(mini, it);
            if (it % 2)
                allOdd = true;
            else
                allEven = true;
        }
        if (!allOdd || !allEven)
            return true;
        if (mini % 2)// mini val is odd number
            return true;
        for (auto& it : nums1) {
            if (it % 2)
                return false;
        }
        return 0;
    }
};
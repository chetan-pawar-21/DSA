class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i=0; i<n; i++){
            int gc = 0;
            long long lc = 1;
            long long prod = 1;
            for(int j=i; j<n; j++){
                gc = gcd(gc, nums[j]);
                lc = lc/gcd(lc, (long long) nums[j]) * nums[j];

                prod*=nums[j];

                if(prod == gc*lc){
                    ans = max(ans, j-i+1);
                }

                if(prod > 25200){
                    break;
                }
            }
        }

        return ans;
    }
};
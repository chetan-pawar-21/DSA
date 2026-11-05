class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        
        for(int i=0; i<arr1.size(); i++){
            int temp = 0;
            for(int j=0; j<arr2.size(); j++){
                if(abs(arr1[i]-arr2[j]) <= d){
                    temp = 1;
                }
            }
            cnt=cnt-temp+1;
        }
        return cnt;
    }
};
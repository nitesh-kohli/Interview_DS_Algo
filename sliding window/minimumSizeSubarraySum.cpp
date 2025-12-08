class Solution {
public:
    int bruteForce(int target, vector<int>& nums){
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum >= target){
                    ans = min(ans, j-i+1);
                    break;
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int r = 0, l = 0;
        int ans = INT_MAX;
        int sum = 0;


        while(r < n){
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
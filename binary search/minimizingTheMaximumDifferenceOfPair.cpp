class Solution {
public:
    int countPair(vector<int>& nums, int mid){
        int cnt = 0;
        int i = 0;
        while(i < nums.size()-1){
            if(nums[i+1] - nums[i] <= mid){
                cnt++;
                i = i + 2;
            }
            else{
                i = i + 1;
            }
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if(n == 0 || p == 0) return 0;

        sort(nums.begin(), nums.end());
        int low = 0, high = nums[n-1] - nums[0];
        
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(countPair(nums, mid) >= p){
                ans = min(ans, mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};
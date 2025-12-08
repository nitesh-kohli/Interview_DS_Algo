class Solution {
public:
    int bruteForce(vector<int>& nums, int k){
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k){
                    ans++;
                }
            }
        }
        return ans;
    }

    int optimalApproach(vector<int>& nums, int k){
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int preSum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        return optimalApproach(nums, k);
    }
};
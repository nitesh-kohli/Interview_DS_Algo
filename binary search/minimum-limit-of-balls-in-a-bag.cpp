class Solution {
public:
    long long requiredOps(vector<int>& nums, int mid) {
        long long cnt = 0;
        for (int num : nums) {
            cnt += (num - 1) / mid;
        }
        return cnt;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (requiredOps(nums, mid) <= maxOperations) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

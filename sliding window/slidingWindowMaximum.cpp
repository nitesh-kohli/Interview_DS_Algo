class Solution {
public:
    vector<int> bruteForce(vector<int>& nums, int k){
        vector<int> ans;
        for(int i = 0; i <= nums.size()-k; i++){
            int temp = nums[i];
            for(int j = 0; j < k; j++){
                temp = max(temp, nums[i+j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    vector<int> optimalApproach(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < n; i++){
            //check for out of boundary for k size window if it remove
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();

            //maintain the decreasing order in deque
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);
            //get the max element from the k size window and store it into the ans
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return optimalApproach(nums, k);
    }
};
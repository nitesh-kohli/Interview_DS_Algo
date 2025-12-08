class Solution {
public:
    bool bruteForce(vector<int>& nums, int k){
        int n = nums.size();
        //distinct indices means i and j are not same
        //j must be i+1
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] == nums[j] && abs(i-j) <= k)
                    return true;
            }
        }
        return false;
    }

    bool optimalApproach(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        unordered_map<int,int> hash;

        for(int r = 0; r < n; r++){
            //found duplicate
            if(hash.find(nums[r]) != hash.end()){
                if(abs(r - hash[nums[r]]) <= k) return true;
                l++;
            }
            
            hash[nums[r]] = r;
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        return optimalApproach(nums, k);
    }
};
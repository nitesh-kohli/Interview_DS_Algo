class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        int n = nums.size();
        for(auto x : nums){
            if(count == 0){
                candidate = x;
                count = 1;
            }
            else if(candidate == x) count++;
            else count--; 
        }

        count = 0;
        for(auto x : nums){
            if(x == candidate) count++;
        }
        return count > n/2 ? candidate : -1;
    }
};
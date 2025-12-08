class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique;
        for(int i = 0; i < nums.size(); i++){
            if(unique.find(nums[i]) != unique.end())
                return true;
            unique.insert(nums[i]);
        }
        return false;
    }
};
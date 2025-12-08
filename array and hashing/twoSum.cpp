class Solution {
public:
    vector<int> bruteForce(vector<int>& nums, int target){
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        for(int i = 0; i < nums.size(); i++){
            pair<int, int> p = {nums[i], i};
            temp.push_back(p);
        }
        sort(temp.begin(), temp.end());
        int l = 0, r = temp.size()-1;
        while(l < r){
            int sum = temp[l].first + temp[r].first;
            if(sum == target)
                return {temp[l].second, temp[r].second};
            else if(sum > target)
                r--;
            else
                l++;
        }
        return {-1, -1};
    }
};
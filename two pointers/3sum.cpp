class Solution {
public:
    vector<vector<int>> bruteForce(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }

    vector<vector<int>> betterSol(vector<int>& nums){
        //1) run two for loop i and j
        //2) use set to store unique triplet
        //3) need hashset to store the possible 3rd element
        //4) hashset will be restored when i incremented
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++){
            unordered_set<int> hashset;
            for(int j = i+1; j < n; j++){
                int third = -(nums[i] + nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    vector<vector<int>> optimalApproach(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;
                else if(sum < 0) j++;
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
       return optimalApproach(nums);
    }
};
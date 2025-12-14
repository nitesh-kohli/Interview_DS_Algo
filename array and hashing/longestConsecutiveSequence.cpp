class Solution {
public:
    bool find(int x, vector<int>& arr){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == x)
                return true;
        }
        return false;
    }

    int bruteForce(vector<int>& arr){
         int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x = arr[i]+1;
            int cnt = 1;
            while(find(x, arr)){
                cnt++;
                x++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
    int better(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) return n;
        int ans = 0;
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] - 1 == nums[i-1])
                cnt++;
            else if(nums[i] == nums[i-1])
                continue;
            else if(nums[i] - 1 != nums[i-1]){
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }

    int optimal(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 1;

        for(auto it : st){
            int x = it;
            //x is the first element of consecutive sequence
            if(st.find(x-1) == st.end()){
                int cnt = 1;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
    int longestConsecutive(vector<int>& nums) {
       return optimal(nums);
    }
};
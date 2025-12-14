class Solution {
public:
    vector<int> bruteForce(vector<int>& nums){
         int n = nums.size();
        vector<int> res;
        vector<int> prefixProd(n);
        vector<int> suffixProd(n);

        prefixProd[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixProd[i] = prefixProd[i-1] * nums[i];
        }

        suffixProd[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            suffixProd[i] = suffixProd[i+1] * nums[i];
        }

        for(int i = 0; i < n; i++){
            if(i == 0) res.push_back(suffixProd[i+1]);
            else if(i == n-1) res.push_back(prefixProd[i-1]);
            else res.push_back(prefixProd[i-1] * suffixProd[i+1]);
        }
        return res;
    }

    vector<int> optimal(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n,1);

        int prefix = 1;
        for(int i = 1; i < n; i++){
            prefix = prefix * nums[i-1];
            res[i] = prefix;
        }

        int suffix = 1;
        for(int i = n-2; i >= 0; i--){
            suffix = suffix * nums[i+1];
            res[i] = res[i] * suffix;
        }
        return res;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        return optimal(nums);
    }
};
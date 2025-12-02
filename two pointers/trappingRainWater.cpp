class Solution {
public:
    int bruteForce(vector<int>& height){
        int ans = 0;
        int n = height.size();
        vector<int> prefixMax(n), suffixMax(n);

        prefixMax[0] = height[0];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }

        suffixMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            ans += min(leftMax, rightMax) - height[i];
        }
        return ans;
    }


    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0, sum = 0, l = 0, r = height.size() - 1;
        while(l < r){
            if(height[l] <= height[r]){
                if(lmax > height[l])
                    sum += lmax-height[l];
                else
                    lmax = height[l];
                l++;
            }
            else{
                if(rmax > height[r])
                    sum += rmax - height[r];
                else
                    rmax = height[r];
                r--;
            }
        }
        return sum;
    }
};
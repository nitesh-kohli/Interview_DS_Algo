class Solution {
public:
    int bruteForce(vector<int>& height){
        int n = height.size();
        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int width = j-i;
                int ht = min(height[i], height[j]);
                int area = width * ht;
                ans = max(ans, area);

            }
        }
        return ans;
    }

    int optimalApproach(vector<int>& height){
       int maxWater = 0;
       int l = 0, r = height.size() - 1;

       while(l < r){
        int width = r-l;
        int ht = min(height[l], height[r]);
        int currWater = ht * width;
        maxWater = max(maxWater, currWater);

        //we only move less height boundary because it is the one
        // who is controlling
        //the height of container 
        height[l] < height[r] ? l++ : r--;
       }
       return maxWater;
    }

    int maxArea(vector<int>& height) {
       return optimalApproach(height);
    }
};
class Solution {
public:
    int bruteForce(vector<int>& prices){
        int n = prices.size();
        int ans = 0;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                ans = max(ans , prices[j] - prices[i]);
            }
        }
        return ans;
    }

    int optimalApproach(vector<int>& prices){
        int n = prices.size();
        int ans = 0;
        int l = 0;
        for(int r = 1; r < n; r++){
            //if diff is negative move l or shrink window
            while(l < r && prices[r] - prices[l] < 0){
                l++;
            }

            //expand
            ans = max(ans, prices[r] - prices[l]);
        }
        return ans;
    }

    int maxProfit(vector<int>& prices) {
       return optimalApproach(prices);
    }
};
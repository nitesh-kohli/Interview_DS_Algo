class Solution {
public:
    int bruteForce(vector<int>& arr){
        int i=0, j, profit = 0, n = arr.size();
        
        while(i < n){
            j = i+1;
            while(j < n){
                if(arr[j] < arr[j-1]){
                    profit += (arr[j-1] - arr[i]);
                    i = j;
                    break;
                }
                else j++;
            }
            if(j == n){
                profit += (arr[j-1] - arr[i]);
                break;
            }
        }
        
        return profit;
    }

    int optimalApproach(vector<int>& prices){
        int n = prices.size();
        int profit = 0;

        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i-1])
                profit += (prices[i] - prices[i-1]);
        }
        return profit;
    }

    int maxProfit(vector<int>& nums) {
       return optimalApproach(nums);
    }
};
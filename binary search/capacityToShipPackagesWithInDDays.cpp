class Solution {
public:
    int weightSum(vector<int>& weights){
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
        }
        return sum;
    }
    int maxWeight(vector<int>& weights){
        int maxi = INT_MIN;
        for(int i = 0; i < weights.size(); i++){
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }
    int daysReq(vector<int>& weights, int cap){
        int load = 0;
        int days = 1;
        for(int i = 0; i < weights.size(); i++){
            if((load + weights[i]) > cap){
                days++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxWeight(weights);
        int high = weightSum(weights);

        while(low <= high){
            int mid = low + (high-low)/2;
            if(daysReq(weights, mid) <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};


//because low started at not possible and high started at possible so
//it low ended at the possible and high ended at not possible
class Solution {
public:
    long long totalHours(vector<int>& piles, int k){
        long long ans = 0;
        for(int i = 0; i < piles.size(); i++){
            ans += (piles[i] + k-1)/k;
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MIN, k = 0, n = piles.size();
        if(n == 1)
            return (piles[0] + h-1)/h;
        
        for(int i = 0; i < piles.size(); i++){
            high = max(high, piles[i]);
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            if(totalHours(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
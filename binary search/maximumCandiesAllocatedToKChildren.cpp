class Solution {
public:
    long long isPossible(vector<int>& candies, int mid){
        long long res = 0;
        for(int candy : candies){
            res += candy/mid;
        }
        return res;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if(sum < k) return 0;
        //find out the search space
        long long low = 1, high = sum/k;
        long long ans = 0;

        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isPossible(candies, mid) >= k){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return (int)ans;
    }
};
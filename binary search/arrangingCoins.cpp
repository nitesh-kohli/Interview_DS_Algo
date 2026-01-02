class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1, high = n;
        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;
            if((1LL*mid*(mid+1))/2 <= n){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};
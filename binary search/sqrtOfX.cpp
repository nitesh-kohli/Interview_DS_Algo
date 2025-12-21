class Solution {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 0) return x;
        int low = 1, high = x/2;

        while(low <= high){
            long long mid = low + (high-low)/ 2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};
// * we have to determine the lower bound and upper bound first, to search our answer in that range.
// * for lower bound how fast we can repair a car, if there is only one car and the first rank guy will repair that.
// * for upperbound how slow we can repair a car, if there are n cars and the last rank guy will repair that.
// * `[min(ranks) * 1*1 , max(ranks) * n*n]`
// * k is no of cars can be repaired by rank[i] when the mini time to repair all cars given is T
// * so k^2 <= floor(sqrt(T/ ranks[i])) , used floor because mechanic can repair whole not 1 car fully repair and other is half repair so took lower value.



class Solution {
public:
    long long isValid(vector<int>& ranks, long long t, int cars){
        long long cnt = 0;
        for(int rank : ranks){
            cnt += floor(sqrt(t/rank));
            if (cnt >= cars) return cnt; 
        }
        return cnt;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        int n = ranks.size();
        long long low = 0, high = 1LL* ranks[n-1]*cars*cars;

        long long ans = high;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isValid(ranks, mid, cars) >= cars){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};
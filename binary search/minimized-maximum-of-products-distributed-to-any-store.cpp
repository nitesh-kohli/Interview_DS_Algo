class Solution {
public:
    int isValid(vector<int>& arr, int mid, int n){
        int cnt = 0;
        for(int ele : arr){
            cnt += (ele + mid - 1)/mid;
        }
        return cnt;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(isValid(quantities, mid, n) <= n){
                ans = min(ans, mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
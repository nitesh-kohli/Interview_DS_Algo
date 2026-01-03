// * we have to find the min capability of the robber to rob the houses.
// * he can rob k houses at least
// * there are n number of ways to rob k houses
// * in each way robber has some max amount he can rob from atleast k house.
// * we have to give min of this max of all ways.
// * so this is a min-max problem. 
// * so binary search on range/answer pattern
// * but what will be the range?
// * what is the min amount robber can rob? min(nums) 😊
// * what is the max amount robber can rob? max(nums)😊
// * so the search space range will be  `[min(nums), max(nums)]`
// * we apply binary search and calculate mid
// * what this mid signifies? mid signifies the min capabilty to rob atleast k house
// * so how do we check if this can be our answer? we do linear search on nums array
// * and count how many there which is <= mid by skipping adjacent.
// * if the count is greater than k that means this ans = mid is possible but we need min
// * so eliminate the right half and search in left half
// * and repeat the process 

class Solution {
public:
    int isValid(vector<int>& nums, int mid){
        int cnt = 0, i = 0;
        while(i < nums.size()){
            //if the nums[i] less or equal to mid
            //then we count this and skip adjacent
            if(nums[i] <= mid){
                cnt++;
                i = i + 2;
            }
            //if nums[i] > mid we can take adjacent so move to i+1
            else{
                i = i + 1;
            }
        }

        return cnt;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int ans = INT_MIN;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isValid(nums, mid) >= k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
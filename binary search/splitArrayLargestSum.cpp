class Solution {
public:
    int subarrayCount(vector<int>& nums, int maxSum){
        int count = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= maxSum)
                sum += nums[i];
            else{
                count++;
                sum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        //I dont know what will be the largest subarray sum which is minimum
        //so i think can it be 1 ?
        //it cannot because elements in the array are greater than 1
        //if i consider only 1 element in the subarray then i know what will the 
        //largest subarray sum? it is the max of element and if all the elements
        //of array gets include in the subarray then the largest sum will be
        // sum(arr)
        //so we need to make subarray of sum from max(arr) till sum(arr) 
        // and compare at which sum we are getting k subarrays

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high-low)/2;
            int count = subarrayCount(nums, mid);
            if(count <= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
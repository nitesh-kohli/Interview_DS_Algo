class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //if single element exist
        if(n == 1) return 0;
        //if array in increasing order
        if(nums[n-1] > nums[n-2]) return n-1;
        //if array in decreasing order
        if(nums[0] > nums[1]) return 0;

        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + (high-low)/2;
            //if mid is peak
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            //if mid is left of peak eliminate left search space
            //if mid is left of peak means it present 
            //on the increasing slope
            else if(nums[mid] > nums[mid-1]){
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return -1;
    }
};
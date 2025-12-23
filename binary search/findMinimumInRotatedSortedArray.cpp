class Solution {
public:
    int bruteForce(vector<int>& nums){
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1])
                return nums[i+1];
        }
        return nums[0];
    }

    int optimal(vector<int>& nums){
        int n = nums.size();
        int l = 0, h = n-1;

        while(l < h){
            int mid = l + (h-l)/2;
            if(nums[mid] > nums[h]) //drop on the right
                l = mid + 1;
            //drop on the left or mid can also be mini. include it
            else
                h = mid; 
        }

        return nums[l];
    }
    int findMin(vector<int>& nums) {
        return optimal(nums);
    }
};
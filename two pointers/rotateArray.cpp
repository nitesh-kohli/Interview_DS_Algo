class Solution {
public:
    void bruteForce(vector<int>& nums, int k){
        int n = nums.size();
        while(k--){
            int temp = nums[n-1];
            for(int i = n-2; i >= 0; i--){
                nums[i+1] = nums[i]; 
            }
            nums[0] = temp;
        }
    }

    //reversal is a minimal, constant-space way to reorder a section of an array
    //reverse an array twice can restore order
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n == 0) return 0;
        int l = 0, r = n-1;
        
        while(l < r){
            while(l < n && nums[l] != val) l++;
            while(r >= 0 && nums[r] == val) r--;
            if(l < n && r >= 0 && l < r){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        if(r < 0) return 0;
        if(l >= n) return n;
        if(nums[l] == val) return l;
        return l+1;
    }
};
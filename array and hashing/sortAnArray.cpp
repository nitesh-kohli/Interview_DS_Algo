class Solution {
public:
    void heapify(vector<int>& nums, int n, int i){
        int parent = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && nums[left] > nums[parent])
            parent = left;
        
        if(right < n && nums[right] > nums[parent])
            parent = right;

        if(parent != i){
            swap(nums[i], nums[parent]);
            heapify(nums, n, parent);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        //heapsort
        //create maxHeap by using heapify 
        //heapify start from first parent node which have left and right child
        //for 0 based indexing array
        //parent = i-1 / 2
        //left child = 2*i - 1
        //right child = 2*i + 2
        //for n-1 leaf node parent will be n/2 - 1
        int n = nums.size();
        for(int i = (n / 2) - 1; i >= 0; i--){
            heapify(nums, n, i);
        }

        //once maxHeap constructed pop the root and store it at the last
        //and root position replaced by last leaf
        for(int i = n-1; i > 0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};
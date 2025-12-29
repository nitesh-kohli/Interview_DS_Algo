class Solution {
  public:
    int isPossible(vector<int>& arr, int maxTime){
        int count = 1;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            if((sum + arr[i]) <= maxTime){
                sum += arr[i];
            }
            else{
                count++;
                sum = arr[i];
            }
        }
        return count;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int partitionCount = isPossible(arr, mid);
            if(partitionCount <= k)
                high = mid - 1;
            else
                low = mid + 1;
                
        }
        return low;
    }
};
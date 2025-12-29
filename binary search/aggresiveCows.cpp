class Solution {
  public:
    //naive approach
    //1.) sort the array. why? because it ensure our answer is correct 
    //when place in greedy
    //2.) we know min distance can be in the range (1, max-min)
    //at each distance we check whether cow placements is possible
    //if possible we continue if not we break the loop and returen
    //before the last element because we know that was the possible one
    
    //we can apply binary search as we see the pattern in the answer
    //ans 1 2 3 4 5 6 7 8 9 
    //   ✅✅✅✅❌❌❌❌❌
    bool isPossible(vector<int> &stalls, int k, int dist){
        int count = 1;
        int slow = 0;
        for(int fast = 1; fast < stalls.size(); fast++){
            if((stalls[fast] - stalls[slow]) >= dist){
                count++;
                slow = fast;
            }
        }
        if(count >= k) return true;
        
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        int low = 1, high = stalls[n-1]-stalls[0];
        if(k == 2) return high;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(stalls, k, mid) == true)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        // for(int i = 1; i <= stalls[n-1]-stalls[0]; i++){
        //     if(isPossible(stalls, k, i) == true)
        //         continue;
        //     else
        //         return i-1;
        // }
        
        return high;
    }
};
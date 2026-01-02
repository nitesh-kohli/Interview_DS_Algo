class Solution {
public:
    int helper(vector<int>& potions, int spell, long long success){
       
        int m = potions.size();
        int low = 0, high = m-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(1LL * spell * potions[mid] < success){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        if(low == m) return 0;
        return m-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(), potions.end());
        for(int spell : spells){
            pairs.push_back(helper(potions, spell, success));
        }
        return pairs;
    }
};
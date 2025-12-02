class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1;
        int boatCount = 0;

        while(l <= r){
            int sum = people[l] + people[r];
            if(sum > limit){
                boatCount++;
                r--;
            }
            else if(sum <= limit){
                boatCount++;
                l++;
                r--;
            }
        }
        if(l == r) boatCount++;
        return boatCount;
    }
};
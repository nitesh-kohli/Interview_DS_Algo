class Solution {
public:
    vector<int> bruteForce(vector<int>& nums){
        set<int> ans;
        int n = nums.size();
        int mm = floor(n/3);
        unordered_map<int, int> mpp;

        for(auto num : nums){
            mpp[num]++;
            if(mpp[num] > mm)
                ans.insert(num);
        }
        return vector<int>(ans.begin(), ans.end());
    }

    vector<int> optimalApproach(vector<int>& nums){
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            else if(num2 == element){
                count2++;
            }
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> output;
        int countMajority = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            if(num2 == element){
                count2++;
            }
        }
        if(count1 > countMajority){
            output.push_back(num1);
        }
        if(count2 > countMajority){
            output.push_back(num2);
        }
        return output;
    }
    vector<int> majorityElement(vector<int>& nums) {
        return optimalApproach(nums);
    }
};
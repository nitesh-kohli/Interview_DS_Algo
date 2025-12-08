class Solution {
public:
    vector<int> bruteForce(vector<int>& arr, int k, int x){
       vector<int> ans;
       vector<pair<int, int>> vec;

       for(int i = 0; i < arr.size(); i++)
            vec.push_back({arr[i], abs(arr[i] - x)});

       sort(vec.begin(), vec.end(), [&](
        const pair<int,int>& a, const pair<int,int>& b){
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first; // tie breaker
        });

       for(int i = 0; i < k; i++)
            ans.push_back(vec[i].first);
       
       sort(ans.begin(), ans.end());
       return ans;
    }

    vector<int> optimalApproach(vector<int>& arr, int k, int x){
        int left = 0;
        int right = arr.size() - 1;

        while (right - left + 1 > k) {
            if (x - arr[left] <= arr[right] - x) {
                right--;
            } else {
                left++;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return optimalApproach(arr, k, x);
    }
};
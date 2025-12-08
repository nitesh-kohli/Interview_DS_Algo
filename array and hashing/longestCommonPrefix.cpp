class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string temp = "";
            int n = ans.length() < strs[i].length() ? ans.length() : strs[i].length();
            for(int j = 0; j < n; j++){
                if(ans[j] == strs[i][j])
                    temp += ans[j];
                else
                    break;
            }
            ans = temp;
        }
        return ans;
    }
};
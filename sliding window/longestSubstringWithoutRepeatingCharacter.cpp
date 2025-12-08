class Solution {
public:
    int bruteForce(string& s){
        int longestSubstr = 0, i, j;
        
        for(i = 0; i < s.length(); i++){
            vector<char> hashset(256, 0);
            for(j = i; j < s.length(); j++){
                if(hashset[s[j]] == 1){
                    longestSubstr = max(longestSubstr, j-i);
                    break;
                }else{
                    hashset[s[j]]++;
                }  
            }
            longestSubstr = max(longestSubstr, j-i);
        }
        return longestSubstr;
    }

    int optimalApproach(string& s){
        vector<int> hash(256, -1);
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0;

        while(r < n){
            //exist in hash
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l)
                    l = hash[s[r]] + 1;
            }

            int len = r-l+1;
            hash[s[r]] = r;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;
    }
    int lengthOfLongestSubstring(string s) {
        return bruteForce(s);
    }
};
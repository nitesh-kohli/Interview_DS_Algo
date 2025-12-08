class Solution {
public:
    int bruteForce(string s, int k){
        int maxLen = 0;
        for(int i = 0; i < s.length(); i++){
            int hash[26] = {0};
            //substring's max frequency
            int maxFreq = 0;
            for(int j = i; j < s.length(); j++){
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']); 
                int changes = (j-i+1) - maxFreq;

                if(changes <= k)
                    maxLen = max(maxLen, j-i+1);
                else
                    break;
            }
        }
        return maxLen;
    }

    int optimalApproach(string s, int k){
        int l = 0, r = 0, maxFreq = 0, maxLen = 0, n = s.length();
        int hash[26] = {0};
        while(r < n){
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            //when conversion greater than k
            if((r-l+1)-maxFreq > k){
                hash[s[l] - 'A']--;
                l++;
            }
            if((r-l+1)-maxFreq <= k)
                maxLen = max(maxLen, r-l+1);
            
            r++;
        }
        return maxLen;
    }
    int characterReplacement(string s, int k) {
       return optimalApproach(s,k);
    }
};
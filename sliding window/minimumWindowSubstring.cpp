class Solution {
public:
    string bruteForce(string s, string t){
        int len =   INT_MAX;
        int startIdx = -1;

        for(int i = 0; i < s.length(); i++){
            vector<int> hash(256);
            int cnt = 0;
            for(int j = 0; j < t.length(); j++){
                hash[t[j]]++;
            }

            for(int j = i; j < s.length(); j++){
                if(hash[s[j]] > 0){
                    cnt++;
                    hash[s[j]]--;
                }
                if(cnt == t.length()){
                    if(j-i+1 < len){
                        len = j-i+1;
                        startIdx = i;
                        break;
                    }
                }
            }
        }
        if (startIdx == -1) return "";
        return s.substr(startIdx, len);
    }
    
    string optimalApproach(string s, string t){
        int n = s.length(), m = t.length();
        int l = 0, r = 0, cnt = 0, len = INT_MAX, startIdx = -1;
        vector<int> hash(256);

        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }

        while(r < n){
            //if any char of t found in s
            if(hash[s[r]] > 0){
                cnt++;
                
            }
            hash[s[r]]--;
            //all t's char found in s
            while(cnt == m){
                if(r-l+1 < len){
                    len = r-l+1;
                    startIdx = l;
                }
                //try to shrink window
                hash[s[l]]++;
                //if during shrinking char frequency again get's inserted
                //reduce count
                //and start expand
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, len);
    }
    string minWindow(string s, string t) {
        return optimalApproach(s, t);
    }
};
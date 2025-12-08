class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false; 
        vector<int> freq(26);
        for(int i = 0; i < s1.length(); i++)
            freq[s1[i] - 'a']++;

        vector<int> windowFreq(26);
        for(int i = 0; i < s1.length(); i++){
            windowFreq[s2[i] - 'a']++;
        }

        if(windowFreq == freq) return true;
        for(int i = s1.length(); i < s2.length(); i++){
            windowFreq[s2[i] - 'a']++;
            windowFreq[s2[i - s1.length()] - 'a']--;
            if(windowFreq == freq) return true;
        }
        return false;
    }
};
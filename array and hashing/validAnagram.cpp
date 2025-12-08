class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash_s(26);
        vector<int> hash_t(26);

        for(auto ch : s){
            hash_s[ch - 'a']++;
        }
        for(auto ch : t){
            hash_t[ch - 'a']++;
        }
        if(hash_s == hash_t) return true;
        return false;
    }
};
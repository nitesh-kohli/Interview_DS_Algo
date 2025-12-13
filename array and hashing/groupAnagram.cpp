class Solution {
public:
    //time complexity- O(n*mlogm) space complexity - O(n)
    vector<vector<string>> bruteForce(vector<string>& strs){
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> anagrams;

        for(auto s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        for(auto it : mp){
            anagrams.push_back(it.second);
        }

        return anagrams;
    }

    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }

    vector<vector<string>> optimal(vector<string>& strs){
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> anagrams;

        for(string s : strs){
            mp[strSort(s)].push_back(s);
        }

        for(auto it : mp){
            anagrams.push_back(it.second);
        }
        return anagrams;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       return optimal(strs);
    }
};
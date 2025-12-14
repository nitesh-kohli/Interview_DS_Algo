class Solution {
  public:
    vector<int> lengths;
    string encode(vector<string>& s) {
        // code here
        //bruteForce
        // string encodedString = "";
        // for(int i = 0; i < s.size(); i++){
        //     lengths.push_back(s[i].length());
        //     encodedString += s[i];
        // }
        // return encodedString;
        
        //optimal
        string encodedString = "";
        for(auto str : s){
            string delimiter = to_string(str.length()) + "#";
            encodedString += (delimiter + str);
        }
        return encodedString;
    }

    vector<string> decode(string& s) {
        // code here
        //bruteForce
        // int start = 0;
        // vector<string> ans;
        // for(int i = 0; i < lengths.size(); i++){
        //     ans.push_back(s.substr(start, lengths[i]));
        //     start += lengths[i];
        // }
        // return ans;
        int n = s.length();
        vector<string> ans;
        int i = 0;
        while(i < n){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j-i));
            ans.push_back(s.substr(j+1, len));
            i = j+1+len;
        }
        return ans;
    }
};
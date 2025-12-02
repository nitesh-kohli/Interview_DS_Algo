class Solution {
public:
    
    bool isPalindrome(string s) {
        int n = s.length();
        string str = "";

        for(int i = 0; i < n; i++){
            if(isalnum(s[i])){
                if(s[i] >= 65 && s[i] <= 90)
                    str += tolower(s[i]);
                else
                    str += s[i];
            }
        }
        cout<<str;
        string str2 = str;
        reverse(str.begin(), str.end());

        return str == str2;
    }
};
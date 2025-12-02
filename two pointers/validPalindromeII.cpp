class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    //TC - O(n.n) SC - O(1)
    bool bruteForce(string s){
        if(isPalindrome(s, 0, s.length()-1)) return true;
        for(int i = 0; i < s.length(); i++){
            string str = "";
            for(int j = 0; j < s.length(); j++){
                if(i == j) continue;
                str += s[j];
            }
            if(isPalindrome(str, 0, str.length()-1)) return true;
        }
        return false;
    }
    //TC - O(n) SC-O(1)
    bool optimalApproach(string s){
        if(s.length() < 3) return true;
        int l = 0, r = s.length()-1;
        while(l < r){
            if(s[l] != s[r]){
                if(isPalindrome(s, l+1, r) ||  isPalindrome(s, l, r-1))
                    return true;
                else return false;
            }
            l++;
            r--;
        }
        return true;
    }


    bool validPalindrome(string s) {
       return optimalApproach(s);
    }
};